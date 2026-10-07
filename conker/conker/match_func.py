#!/usr/bin/env python3
"""Checks one function's C against the ROM, without building the whole ROM.

    python3 match_func.py FUNC [CANDIDATE.c] [--diff] [--m2c-out FILE]

Run from conker/conker inside the conker-decomp Docker image (IDO and binutils are
Linux x86-64), with the whole CBFD-Recompiled tree mounted (m2c is in ../../tools/m2c):

    docker run --rm --platform linux/amd64 -v $REPO:/repo -w /repo/conker/conker \\
        conker-decomp python3 match_func.py func_10001194 --diff

The target is the function's asm/nonmatchings/.../FUNC.s, whose comments hold the
ROM's instruction words. The candidate (CANDIDATE.c, or m2c's output without one)
replaces FUNC's #pragma GLOBAL_ASM in its source file; the file's other pragmas are
dropped, and it is compiled with IDO and the file's flags from the Makefile. Words
are compared with relocated fields masked (a jal's target, a %hi/%lo's half), so
symbol names don't matter but everything else does. Prints MATCH, or how many words
differ (exit status 0 only for a match); --diff shows both listings side by side.
"""
import glob
import os
import re
import subprocess
import sys
import tempfile

IDO = os.environ.get('IDO_CC', '../ido/ido5.3_recomp/cc')
CFLAGS = ('-G 0 -Xfullwarn -Xcpluscomm -signed -nostdinc -non_shared -Wab,-r4300_mul -D_LANGUAGE_C -D_FINALROM '
          '-DF3DEX_GBI_2 -D_MIPS_SZLONG=32 -woff 649,838 -I . -I include -I include/2.0L -I include/2.0L/PR '
          '-I include/libc -I src/libultra/os -I src/libultra/audio -I src/libultra/io').split()
MIPSBIT = ['-mips2', '-o32']
M2C = '../../tools/m2c/m2c.py'
WORD_RE = re.compile(r'/\* [0-9A-F]+ [0-9A-F]+ ([0-9A-F]{8}) \*/\s*(.*)')


def run(cmd, **kw):
    return subprocess.run(cmd, capture_output=True, text=True, **kw)


def find_target(func):
    hits = glob.glob(f'asm/nonmatchings/**/{func}.s', recursive=True)
    if not hits:
        sys.exit(f'no asm/nonmatchings/**/{func}.s')
    return hits[0]


def find_source(rel):
    # The linked file whose pragma includes it (not src/game/'s drafts): the guess from
    # the .s path first (asm/nonmatchings/FILE/FUNC.s is in src/FILE.c), then all files.
    needle = f'"{rel}"'
    guess = 'src/' + rel[len('asm/nonmatchings/'):].rsplit('/', 1)[0] + '.c'
    if os.path.exists(guess) and needle in open(guess, encoding='utf-8', errors='replace').read():
        return guess
    for path in glob.glob('src/**/*.c', recursive=True):
        if '/game/' in path.replace('\\', '/'):
            continue
        text = open(path, encoding='utf-8', errors='replace').read()
        if needle in text:
            return path
    sys.exit(f'no source file includes {rel}')


def opt_flags(path):
    flags = '-O2 -g3'
    obj = f'$(BUILD_DIR)/$(SRC_DIR)/{path[len("src/"):]}.o'
    for line in open('Makefile'):
        m = re.match(r'^\$\(BUILD_DIR\)/\$\(SRC_DIR\)/(\S+): OPT_FLAGS := (.*)$', line.strip())
        if not m:
            continue
        pattern, value = m.group(1), m.group(2)
        regex = '^' + re.escape(f'$(BUILD_DIR)/$(SRC_DIR)/{pattern}').replace('%', '.*') + '$'
        if re.match(regex, obj):
            flags = value
    return flags.split()


def target_words(asm_path):
    words, text = [], []
    for line in open(asm_path):
        m = WORD_RE.search(line)
        if m:
            words.append(int(m.group(1), 16))
            text.append(m.group(2).strip())
    return words, text


def context_stub(path, out):
    # The file's #includes, #defines and top-level declarations (m2c's context).
    depth, kept = 0, []
    for line in open(path, encoding='utf-8', errors='replace').read().split('\n'):
        code = re.sub(r'//.*', '', line)
        if depth == 0 and (code.startswith('#include') or code.startswith('#define')
                           or (code.rstrip().endswith(';') and not code[:1].isspace())):
            kept.append(line)
        depth += code.count('{') - code.count('}')
    open(out, 'w').write('\n'.join(kept) + '\n')


def m2c(path, asm_path, tmp):
    stub = os.path.join(tmp, 'ctx_stub.c')
    ctx = os.path.join(tmp, 'ctx.c')
    context_stub(path, stub)
    run(['gcc', '-E', '-P', '-Iinclude', '-Iinclude/2.0L', '-Iinclude/2.0L/PR', '-Isrc', f'-I{os.path.dirname(path)}',
         '-D_LANGUAGE_C', '-ffreestanding', '-DF3DEX_GBI_2', '-DM2CTX', stub, '-o', ctx])
    r = run([sys.executable, M2C, '-t', 'mips-ido-c', '--valid-syntax', '--context', ctx, asm_path])
    if r.returncode != 0:
        return None, r.stderr
    return clean_m2c(r.stdout, open(path, encoding='utf-8', errors='replace').read()), ''


def expand_fields(text):
    # m2c's --valid-syntax M2C_FIELD(expr, type_ptr, offset), written out (innermost first).
    while (i := text.rfind('M2C_FIELD(')) >= 0:
        args, depth, start, j = [], 0, i + len('M2C_FIELD('), i + len('M2C_FIELD(')
        while True:
            c = text[j]
            if c == '(':
                depth += 1
            elif c == ')' and depth == 0:
                args.append(text[start:j].strip())
                break
            elif c == ')':
                depth -= 1
            elif c == ',' and depth == 0:
                args.append(text[start:j].strip())
                start = j + 1
            j += 1
        expr, type_ptr, offset = args
        text = text[:i] + f'(*({type_ptr})((char *)({expr}) + {offset}))' + text[j + 1:]
    return text


def clean_m2c(text, source):
    # As auto_decomp.py: m2c's placeholders as C the file's IDO takes.
    text = expand_fields(text)
    for unk, t in (('M2C_UNK8', 's8'), ('M2C_UNK16', 's16'), ('M2C_UNK32', 's32'), ('M2C_UNK64', 's64'),
                   ('M2C_UNK', 's32')):
        text = re.sub(r'\b' + unk + r'\b', t, text)
    lines = []
    for line in text.strip('\n').split('\n'):
        m = re.match(r'^(.*?)\b((?:func|D)_[0-9A-F]{8}|[A-Za-z_]\w*)\(.*\);\s*/\* (extern|static) \*/$', line)
        if m:
            if re.search(r'\b' + re.escape(m.group(2)) + r'\s*\(', source):
                continue
            line = re.sub(r'^\?\s*', 'void ', line)
        if re.match(r'^extern\b.*;$', line) and re.search(r'\b' + re.escape(line.rstrip(';').split()[-1].lstrip('*')) + r'\b', source):
            continue
        line = re.sub(r'(^|[(,]|\bextern)(\s*)\?(?=[\s*),;])', r'\1\2s32', line)
        lines.append(line)
    return '\n'.join(lines) + '\n'


def compile_candidate(path, rel, candidate, flags, tmp):
    text = open(path, encoding='utf-8', errors='replace').read()
    pragma_re = re.compile(r'^\s*#pragma GLOBAL_ASM\("([^"]+)"\)\s*$', re.M)
    def repl(m):
        return candidate if m.group(1) == rel else ''
    source = pragma_re.sub(repl, text)
    src = os.path.join(tmp, 'candidate.c')
    obj = os.path.join(tmp, 'candidate.o')
    open(src, 'w').write(source)
    r = run([IDO, '-c', '-32'] + CFLAGS + [f'-I{os.path.dirname(path)}'] + flags + MIPSBIT + ['-o', obj, src])
    if r.returncode != 0 or not os.path.exists(obj):
        return None, (r.stdout + r.stderr)
    return obj, ''


def candidate_words(obj, func):
    r = run(['mips-linux-gnu-objdump', '-d', '-r', '-z', '--no-show-raw-insn', obj])
    dis = run(['mips-linux-gnu-objdump', '-d', '-r', '-z', obj]).stdout
    words, relocs, text, symbols = [], {}, [], {}
    inside = False
    base = None
    for line in dis.splitlines():
        if re.match(r'^[0-9a-f]+ <' + re.escape(func) + r'>:$', line):
            inside = True
            continue
        if inside and re.match(r'^[0-9a-f]+ <.*>:$', line):
            break
        if not inside:
            continue
        m = re.match(r'^\s+([0-9a-f]+):\s+([0-9a-f]{8})\s+(.*)$', line)
        if m:
            off = int(m.group(1), 16)
            if base is None:
                base = off
            words.append(int(m.group(2), 16))
            text.append(m.group(3).strip())
            continue
        m = re.match(r'^\s+([0-9a-f]+):\s+(R_MIPS_\w+)\s+(.*)$', line)
        if m and base is not None:
            idx = (int(m.group(1), 16) - base) // 4
            relocs[idx] = m.group(2)
            symbols[idx] = re.sub(r'[+-]0x[0-9a-f]+$', '', m.group(3).strip())
    return words, relocs, text, symbols


def target_symbol(asm_text):
    # The symbol a target instruction refers to: jal NAME, %hi(NAME), %lo(NAME).
    m = re.search(r'\bjal\s+([A-Za-z_]\w*)', asm_text) or re.search(r'%(?:hi|lo)\(([A-Za-z_]\w*)', asm_text)
    return m.group(1) if m else None


def near_data(a, b):
    # D_<address> symbols a field's offset apart: the same memory named from its base.
    ma, mb = re.fullmatch(r'D_([0-9A-F]{8})', a), re.fullmatch(r'D_([0-9A-F]{8})', b)
    return bool(ma and mb and abs(int(ma.group(1), 16) - int(mb.group(1), 16)) < 0x1000)


def mask(word, reloc):
    if reloc == 'R_MIPS_26':
        return word & 0xFC000000
    if reloc in ('R_MIPS_HI16', 'R_MIPS_LO16', 'R_MIPS_GPREL16', 'R_MIPS_GOT16', 'R_MIPS_CALL16'):
        return word & 0xFFFF0000
    return word


def target_jump_tables(asm_path, want_text):
    # The function's jump tables as offsets from its start: from its own .s (rodata
    # migrated into it) or the unmigrated split's rodata (rodata_src/).
    text = open(asm_path).read()
    m = re.search(r'/\* [0-9A-F]+ ([0-9A-F]{8}) [0-9A-F]{8} \*/', text)
    if not m:
        return []
    start = int(m.group(1), 16)
    names = sorted(set(re.findall(r'%(?:hi|lo)\((jtbl_[0-9A-F]{8})\)', text)))
    sources = [text] + [open(p).read() for p in sorted(glob.glob('rodata_src/*.s'))] if names else []
    out = []
    for name in names:
        for src in sources:
            mm = re.search(r'glabel ' + re.escape(name) + r'\n((?:.*\.word\s+\.L\w+.*\n)+)', src)
            if mm:
                out += [int(a, 16) - start for a in re.findall(r'\.word\s+\.L([0-9A-F]{8})', mm.group(1))]
                break
    return out


def candidate_jump_tables(obj, func):
    # Rodata words relocated against .text that land in the function, in order.
    sym = run(['mips-linux-gnu-objdump', '-t', obj]).stdout
    m = re.search(r'^([0-9a-f]{8}) .*\.text\s+([0-9a-f]{8}) ' + re.escape(func) + r'$', sym, re.M)
    if not m:
        return []
    fstart, fsize = int(m.group(1), 16), int(m.group(2), 16)
    rel = run(['mips-linux-gnu-objdump', '-r', '-j', '.rodata', obj]).stdout
    offs = [int(o, 16) for o in re.findall(r'^([0-9a-f]{8}) R_MIPS_32\s+\.text\s*$', rel, re.M)]
    dump = run(['mips-linux-gnu-objdump', '-s', '-j', '.rodata', obj]).stdout
    data = bytearray()
    for line in dump.splitlines():
        mm = re.match(r'^ [0-9a-f]{4,} ((?:[0-9a-f]{2,8} ){1,4})', line + ' ')
        if mm:
            data += bytes.fromhex(mm.group(1).replace(' ', ''))
    out = []
    for o in sorted(offs):
        v = int.from_bytes(data[o:o + 4], 'big')
        if fstart <= v < fstart + fsize:
            out.append(v - fstart)
    return out


def main():
    args = [a for a in sys.argv[1:]]
    show_diff = '--diff' in args
    m2c_out = None
    if '--m2c-out' in args:
        i = args.index('--m2c-out')
        m2c_out = args[i + 1]
        del args[i:i + 2]
    args = [a for a in args if not a.startswith('--')]
    if not args:
        sys.exit(__doc__)
    func = args[0]
    asm_path = find_target(func)
    rel = asm_path
    path = find_source(rel)
    flags = opt_flags(path)
    want, want_text = target_words(asm_path)
    with tempfile.TemporaryDirectory() as tmp:
        if len(args) > 1:
            candidate = open(args[1]).read()
        else:
            candidate, err = m2c(path, asm_path, tmp)
            if candidate is None:
                print(f'{func}: m2c failed: {err.strip()[:300]}')
                return 2
            if m2c_out:
                open(m2c_out, 'w').write(candidate)
        obj, err = compile_candidate(path, rel, candidate, flags, tmp)
        if obj is None:
            print(f'{func}: compile error ({path}, {" ".join(flags)}):\n{err.strip()[:2000]}')
            return 3
        got, relocs, got_text, symbols = candidate_words(obj, func)
        jt_got = candidate_jump_tables(obj, func)
    jt_want = target_jump_tables(asm_path, want_text)
    if not got:
        print(f'{func}: not in the compiled object')
        return 3
    # Alignment nops IDO adds after a file's last function aren't part of it.
    while len(got) > len(want) and got[-1] == 0:
        got.pop()
    n = max(len(want), len(got))
    differ, sym_mismatch = [], []
    for i in range(n):
        if i >= len(want) or i >= len(got):
            differ.append(i)
            continue
        r = relocs.get(i)
        if mask(want[i], r) != mask(got[i], r):
            differ.append(i)
            continue
        # A relocated field must name the same symbol (a file's own sections aside:
        # its rodata, jump tables and statics have no names in the object).
        sym, want_sym = symbols.get(i), target_symbol(want_text[i]) if i < len(want_text) else None
        if sym and want_sym and not sym.startswith('.') and sym != want_sym and not near_data(sym, want_sym):
            differ.append(i)
            sym_mismatch.append(f'{i * 4:X}: {sym} (ROM: {want_sym})')
    if jt_want != jt_got:
        bad_entries = [i for i in range(max(len(jt_want), len(jt_got)))
                       if i >= len(jt_want) or i >= len(jt_got) or jt_want[i] != jt_got[i]]
        print(f'{func}: jump table differs in {len(bad_entries)} of {len(jt_want)} entries '
              f'(entry {bad_entries[0]}: ROM +0x{jt_want[bad_entries[0]] if bad_entries[0] < len(jt_want) else -1:X}, '
              f'yours +0x{jt_got[bad_entries[0]] if bad_entries[0] < len(jt_got) else -1:X})')
        if not differ:
            return 1
    if not differ:
        print(f'{func}: MATCH ({len(want)} words, {path}, {" ".join(flags)})')
        return 0
    print(f'{func}: {len(differ)} of {len(want)} words differ (candidate has {len(got)}; {path}, {" ".join(flags)})')
    for m in sym_mismatch:
        print(f'   wrong symbol at {m}')
    if show_diff:
        bad = set(differ)
        for i in range(n):
            w = want_text[i] if i < len(want_text) else ''
            g = got_text[i] if i < len(got_text) else ''
            mark = '!!' if i in bad else '  '
            print(f'{mark} {i * 4:4X}  {w:<48} | {g}')
    return 1


if __name__ == '__main__':
    sys.exit(main())
