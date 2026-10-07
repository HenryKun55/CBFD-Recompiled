#!/usr/bin/env python3
"""Moves a source file's rodata into its own object, so its functions can become C.

Conker's code and its data/rodata are in different segments (and VRAM ranges), so
splat leaves all rodata in anonymous asm/data chunks, which a function with a jump
table or a float literal can't be decompiled against: its C would emit them again.
For a file in rodata_migrated.txt ("FILE START END", ROM offsets), this
  - yaml:   makes [START, END) one `.rodata, FILE` subsegment of conker.us.yaml (the
            linker script then puts build/src/FILE.c.o's .rodata there);
  - inject: after `make extract`, appends each rodata label of that range to the
            GLOBAL_ASM function that uses it (asm/nonmatchings/FILE/FUNC.s), as
            .rdata (arrays, strings) or .late_rodata (jump tables, float literals),
            which asm-processor puts in the C object as IDO would. Labels the file's
            C functions use are left to them (they compile their own).
  - plan FILE...: works out each file's range from rodata_src/ (asm/data/*.rodata.s
            as splat wrote them without any migration) and prints the lines to add.
The contents come from rodata_src/ and conker.us.bin, so they don't depend on what
splat writes once a range belongs to a file.

    python3 rodata_migrate.py plan FILE...
    python3 rodata_migrate.py yaml
    python3 rodata_migrate.py inject
"""
import glob
import json
import os
import re
import sys

YAML = 'conker.us.yaml'
LIST = 'rodata_migrated.txt'
NAME_RE = re.compile(r'\b((?:D|jtbl)_[0-9A-F]{8}\w*)')


def load_labels():
    # (rom, name, lines) of every rodata label, in ROM order, from the unmigrated split.
    out = []
    for f in sorted(glob.glob('rodata_src/*.rodata.s')):
        cur = None
        for line in open(f):
            m = re.match(r'^glabel (\S+)', line)
            if m:
                cur = [None, m.group(1), []]
                out.append(cur)
                continue
            if cur is None:
                continue
            if line.startswith('enddlabel') or line.startswith('.align') or not line.strip():
                continue
            m = re.search(r'/\* ([0-9A-F]+) [0-9A-F]{8}', line)
            if m and cur[0] is None:
                cur[0] = int(m.group(1), 16)
            cur[2].append(line.rstrip('\n'))
    out = [tuple(x) for x in out if x[0] is not None]
    out.sort()
    return out


def migrated():
    if not os.path.exists(LIST):
        return []
    rows = []
    for line in open(LIST):
        line = line.split('#')[0].strip()
        if line:
            f, a, b = line.split()
            rows.append((f, int(a, 16), int(b, 16)))
    return rows


def file_functions(fileid):
    # The file's GLOBAL_ASM functions in text order, with their .s paths.
    src = open(f'src/{fileid}.c', encoding='utf-8', errors='replace').read()
    funcs = []
    for m in re.finditer(r'^[ \t]*#pragma GLOBAL_ASM\("(asm/nonmatchings/[^"]+/(\w+)\.s)"\)', src, re.M):
        funcs.append((m.group(2), m.group(1)))
    return funcs, src


def c_names(src):
    # Names the file's C code uses as symbols (not in its pragmas, comments or
    # bare extern declarations).
    code = re.sub(r'^[ \t]*#pragma GLOBAL_ASM[^\n]*', '', src, flags=re.M)
    code = re.sub(r'/\*.*?\*/', '', code, flags=re.S)
    code = re.sub(r'//[^\n]*', '', code)
    code = re.sub(r'^\s*extern\b[^;]*;', '', code, flags=re.M)
    return set(NAME_RE.findall(code))


def matched_functions(fileid):
    # The file's C functions' assembly (splat's disassemble_all).
    return {os.path.basename(p)[:-2]: open(p).read() for p in glob.glob(f'asm/matchings/{fileid}/*.s')}


def late(name, lines, refs_text):
    if name.startswith('jtbl_'):
        return True
    if any('.float' in l or '.double' in l for l in lines):
        return True
    # Loaded as a float/double literal.
    return bool(re.search(r'\b(lwc1|ldc1)\s+\$f\d+,\s*%lo\(' + re.escape(name) + r'\)', refs_text))


def data_lines(rom, lines, size, binary):
    # Jump tables and doubles as written; anything else as raw words from the ROM.
    if any(re.search(r'\.word\s+[.A-Za-z_]', l) for l in lines) or any('.double' in l for l in lines):
        return [re.sub(r'/\*.*?\*/', '', l).strip() for l in lines]
    out = []
    data = binary[rom:rom + size]
    for i in range(0, len(data) - len(data) % 4, 4):
        out.append(f'.word 0x{int.from_bytes(data[i:i + 4], "big"):08X}')
    for b in data[len(data) - len(data) % 4:]:
        out.append(f'.byte 0x{b:02X}')
    return out


def plan(files):
    labels = load_labels()
    binary = open('conker.us.bin', 'rb').read()
    names = {n for _, n, _ in labels}
    owner = {}
    for path in glob.glob('asm/nonmatchings/**/*.s', recursive=True) + glob.glob('asm/matchings/**/*.s', recursive=True):
        fid = re.split(r'asm/(?:non)?matchings/', path)[1].rsplit('/', 1)[0]
        for n in set(NAME_RE.findall(open(path).read())):
            if n in names:
                owner.setdefault(n, set()).add(fid)
    for path in glob.glob('src/**/*.c', recursive=True):
        if '/game/' in path.replace('\\', '/'):
            continue
        fid = path[4:-2]
        for n in c_names(open(path, encoding='utf-8', errors='replace').read()):
            if n in names:
                owner.setdefault(n, set()).add(fid)
    for path in glob.glob('asm/*.s') + glob.glob('asm/**/*.s', recursive=True):
        if '/nonmatchings/' in path or '/matchings/' in path or '/data/' in path:
            continue
        fid = path[4:-2]
        for n in set(NAME_RE.findall(open(path).read())):
            if n in names:
                owner.setdefault(n, set()).add(fid)
    for f in files:
        idx = [i for i, (_, n, _) in enumerate(labels) if owner.get(n) == {f}]
        if not idx:
            print(f'# {f}: no rodata of its own')
            continue
        # Its runs of labels (nobody's labels between its own join them); the longest
        # is its rodata, others are data splat typed as rodata (display lists...).
        runs, cur = [], [idx[0]]
        for i in idx[1:]:
            between = {o for j in range(cur[-1] + 1, i) for o in owner.get(labels[j][1], set())}
            if between - {f}:
                runs.append(cur)
                cur = [i]
            else:
                cur.append(i)
        runs.append(cur)
        # Prefer the run with jump tables and float literals (real rodata).
        def score(run):
            rodata = sum(1 for i in run if labels[i][1].startswith('jtbl_')
                         or any('.float' in l or '.double' in l for l in labels[i][2]))
            return (rodata, len(run))
        best = max(runs, key=score)
        first, last = best[0], best[-1]
        if len(runs) > 1:
            print(f'# {f}: {len(runs) - 1} other run(s) of labels left as data')
        # Unreferenced labels right after the last one (padding, string tails) too.
        end_i = last + 1
        while end_i < len(labels) and not owner.get(labels[end_i][1]):
            end_i += 1
        end = labels[end_i][0] if end_i < len(labels) else None
        if end is None:
            print(f'# {f}: runs to the end')
            continue
        try:
            assign(f, labels[first][0], end, labels, binary)
        except Problem as e:
            print(f'# {f}: {e}')
            continue
        print(f'{f} {labels[first][0]:X} {end:X}')


def yaml():
    rows = migrated()
    text = open(YAML).read()
    lines = text.split('\n')
    entry_re = re.compile(r'^(\s*)- \[0x([0-9A-F]+), (\.?rodata)(?:, ([^\]]+))?\]')
    for f, a, b in rows:
        if re.search(r'\[0x%X, \.rodata, %s\]' % (a, re.escape(f)), '\n'.join(lines)):
            continue
        # The rodata entries of the segment holding [a, b).
        idx = [i for i, l in enumerate(lines) if entry_re.match(l)]
        starts = [(int(entry_re.match(lines[i]).group(2), 16), i) for i in idx]
        before = [(s, i) for s, i in starts if s <= a]
        if not before:
            sys.exit(f'{f}: no rodata entry before 0x{a:X}')
        _, at = before[-1]
        indent = entry_re.match(lines[at]).group(1)
        # Entries strictly inside (a, b) go; one at b stays (or a new one starts there).
        inside = [i for s, i in starts if a < s < b]
        has_end = any(s == b for s, _ in starts)
        has_start = any(s == a for s, _ in starts)
        new = []
        for i, l in enumerate(lines):
            if i in inside:
                continue
            if has_start and entry_re.match(l) and int(entry_re.match(l).group(2), 16) == a:
                new.append(f'{indent}- [0x{a:X}, .rodata, {f}]')
                if not has_end:
                    new.append(f'{indent}- [0x{b:X}, rodata]')
                continue
            new.append(l)
            if not has_start and i == at:
                new.append(f'{indent}- [0x{a:X}, .rodata, {f}]')
                if not has_end:
                    new.append(f'{indent}- [0x{b:X}, rodata]')
        lines = new
    open(YAML, 'w').write('\n'.join(lines))


class Problem(Exception):
    pass


def addr_of(label):
    return re.match(r'\.L([0-9A-F]{8})', label).group(1)


def define_label(text, label):
    # A jump target's label before its instruction, if the split didn't write one.
    if re.search(r'^\s*(?:glabel\s+|jlabel\s+)?' + re.escape(label) + r':?\s*$', text, re.M):
        return text
    return re.sub(r'^(\s*/\* [0-9A-F]+ ' + addr_of(label) + r' )', f'  jlabel {label}\n' + r'\1', text, count=1, flags=re.M)


def assign(f, a, b, labels, binary):
    # Which GLOBAL_ASM function each rodata label of [a, b) goes into, and how.
    funcs, src = file_functions(f)
    cnames = c_names(src)
    texts = {name: open(path).read() for name, path in funcs}
    ctexts = matched_functions(f)
    mine = [l for l in labels if a <= l[0] < b]
    blocks = {name: {'rdata': [], 'late': []} for name, _ in funcs}
    prev_owner = None
    for k, (rom, name, lines) in enumerate(mine):
        nxt = mine[k + 1][0] if k + 1 < len(mine) else b
        word = re.compile(r'\b' + re.escape(name) + r'\b')
        users = [fn for fn, _ in funcs if word.search(texts[fn])]
        c_users = [fn for fn, t in ctexts.items() if word.search(t)]
        if name in cnames:
            raise Problem(f'its C code names {name} (should be a literal)')
        if c_users:
            if users:
                raise Problem(f'{name} is used by both C ({c_users[0]}) and asm ({users[0]})')
            prev_owner = None   # the C function compiles it
            continue
        # A jump table belongs to the function holding its targets (by address: the
        # split may not have labelled them, its rodata being the file's now).
        targets = set(re.findall(r'\.word\s+(\.L\w+)', '\n'.join(lines)))
        if targets:
            def holds(text):
                return any(re.search(r'/\* [0-9A-F]+ ' + addr_of(t) + r' ', text) for t in targets)
            holders = [fn for fn, _ in funcs if holds(texts[fn])]
            c_holders = [fn for fn, t in ctexts.items() if holds(t)]
            if c_holders and not holders:
                prev_owner = None   # a C function's switch: it compiles its own
                continue
            if not holders:
                raise Problem(f'no function holds the targets of {name}')
            users = holders[:1]
            for t in targets:
                texts[users[0]] = define_label(texts[users[0]], t)
        fn = users[0] if users else prev_owner
        if fn is None:
            continue            # part of a C function's (padding, an unnamed part)
        prev_owner = fn
        section = 'late' if late(name, lines, texts[fn]) else 'rdata'
        blocks[fn][section].append((name, data_lines(rom, lines, nxt - rom, binary)))
    return funcs, texts, blocks


def inject():
    labels = load_labels()
    binary = open('conker.us.bin', 'rb').read()
    problems = []
    for f, a, b in migrated():
        try:
            funcs, texts, blocks = assign(f, a, b, labels, binary)
        except Problem as e:
            problems.append(f'{f}: {e}')
            continue
        for fn, path in funcs:
            bl = blocks[fn]
            if not bl['rdata'] and not bl['late']:
                continue
            out = [texts[fn].rstrip('\n'), '']
            if bl['rdata']:
                out.append('.rdata')
                for name, data in bl['rdata']:
                    out.append(f'glabel {name}')
                    out.extend(data)
                out.append('')
            if bl['late']:
                out.append('.late_rodata')
                for name, data in bl['late']:
                    out.append(f'glabel {name}')
                    out.extend(data)
                out.append('')
            out.append('.text')
            open(path, 'w').write('\n'.join(out) + '\n')
        print(f'{f}: rodata injected into {sum(1 for x in blocks.values() if x["rdata"] or x["late"])} functions')
    if problems:
        sys.exit('rodata migration failed (take these out of ' + LIST + '):\n  ' + '\n  '.join(problems))


if __name__ == '__main__':
    if len(sys.argv) < 2 or sys.argv[1] not in ('plan', 'yaml', 'inject'):
        sys.exit(__doc__)
    {'plan': lambda: plan(sys.argv[2:]), 'yaml': yaml, 'inject': inject}[sys.argv[1]]()
