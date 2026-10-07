#!/usr/bin/env python3
"""Integrates a batch of matched candidates into src/, file by file, keeping the ROM matching.

    python3 integrate_batch.py LIST.txt     (one function name per line)

Run in the conker-decomp image from conker/conker. For each function: match_func.py must
print MATCH for build/cand/FUNC.c. Then per source file: all of its matches go in at once;
if the object doesn't build, they go in one at a time (keeping those that build). A file
whose rodata isn't migrated (rodata_migrated.txt) can't take functions that add rodata
(float literals, jump tables): those are left out. Finally the whole ROM is built; prints
what went in, what was left out and why (build/integrate_report.txt).
"""
import glob
import os
import re
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor


def run(cmd, **kw):
    return subprocess.run(cmd, capture_output=True, text=True, **kw)


def pragma_re(func):
    return re.compile(r'^[ \t]*#pragma GLOBAL_ASM\("asm/nonmatchings/([^"]*)/' + re.escape(func) + r'\.s"\)[ \t]*$', re.M)


def source_of(func):
    for path in glob.glob('src/**/*.c', recursive=True):
        if '/game/' in path:
            continue
        if pragma_re(func).search(open(path, encoding='utf-8', errors='replace').read()):
            return path
    return None


def rodata_size(obj):
    out = run(['mips-linux-gnu-objdump', '-h', obj]).stdout
    m = re.search(r'\.rodata\s+([0-9a-f]+)', out)
    return int(m.group(1), 16) if m else 0


def data_sizes(obj):
    # .data and .bss: no file's are migrated yet, so they must not change.
    out = run(['mips-linux-gnu-objdump', '-h', obj]).stdout
    return tuple(int(m.group(1), 16) if m else 0
                 for m in (re.search(r'\s\.' + s + r'\s+([0-9a-f]+)', out) for s in ('data', 'bss')))


def build_obj(path):
    obj = f'build/{path}.o'
    if os.path.exists(obj):
        os.remove(obj)
    r = run(['make', obj])
    return r.returncode == 0 and os.path.exists(obj), r.stdout + r.stderr


def insert(path, func):
    cand = open(f'build/cand/{func}.c').read().strip('\n')
    text = open(path, encoding='utf-8', errors='replace').read()
    open(path, 'w', newline='\n').write(pragma_re(func).sub(lambda m: cand, text, count=1))


def main():
    funcs = [l.strip() for l in open(sys.argv[1]) if l.strip()]
    report = []
    # 1. Re-check every claim.
    def check(f):
        if not os.path.exists(f'build/cand/{f}.c'):
            return f, False, 'no candidate'
        if '#pragma GLOBAL_ASM' in open(f'build/cand/{f}.c').read():
            return f, False, 'candidate has a pragma'
        r = run([sys.executable, 'match_func.py', f, f'build/cand/{f}.c'])
        return f, ': MATCH' in r.stdout, r.stdout.strip().split('\n')[0]
    with ThreadPoolExecutor(8) as ex:
        checked = list(ex.map(check, funcs))
    good = [f for f, ok, _ in checked if ok]
    for f, ok, why in checked:
        if not ok:
            report.append(f'{f}\tnot a match\t{why}')
    migrated = {l.split()[0]: int(l.split()[2], 16) - int(l.split()[1], 16) for l in open('rodata_migrated.txt') if l.strip()}
    by_file = {}
    for f in good:
        p = source_of(f)
        if p is None:
            report.append(f'{f}\tno pragma\t')
            continue
        by_file.setdefault(p, []).append(f)
    # 2. Per file.
    done = []
    for path, fs in sorted(by_file.items()):
        fileid = path[4:-2]
        original = open(path, encoding='utf-8', errors='replace').read()
        ok, _ = build_obj(path)
        base_rodata = rodata_size(f'build/{path}.o') if ok else 0
        base_data = data_sizes(f'build/{path}.o') if ok else (0, 0)
        for f in fs:
            insert(path, f)
        ok, log = build_obj(path)
        def rodata_ok():
            # A migrated file's rodata must still fill its range exactly.
            size = rodata_size(f'build/{path}.o')
            return size == migrated[fileid] if fileid in migrated else size == base_rodata
        if ok and rodata_ok() and data_sizes(f'build/{path}.o') == base_data:
            done += fs
            report += [f'{f}\tin\t{path}' for f in fs]
            continue
        # One at a time.
        open(path, 'w', newline='\n').write(original)
        for f in fs:
            before = open(path, encoding='utf-8', errors='replace').read()
            insert(path, f)
            ok, log = build_obj(path)
            if not ok:
                err = next((l for l in log.splitlines() if 'Error' in l or 'error' in l), 'build error')
                report.append(f'{f}\tleft out\tdoesn\'t build: {err[:160]}')
            elif data_sizes(f'build/{path}.o') != base_data:
                report.append(f'{f}\tleft out\tadds data/bss to {fileid}')
                ok = False
            elif not rodata_ok():
                report.append(f'{f}\tleft out\tchanges the rodata of {fileid}')
                ok = False
            if ok:
                done.append(f)
                report.append(f'{f}\tin\t{path}')
            else:
                open(path, 'w', newline='\n').write(before)
        build_obj(path)
    # 3. The whole ROM.
    r = run(['make', '-j8'])
    rom_ok = 'conker.us.bin: OK' in r.stdout
    open('build/integrate_report.txt', 'w').write('\n'.join(report) + '\n')
    print(f'{len(done)} of {len(funcs)} in; ROM {"OK" if rom_ok else "FAILED"}')
    if not rom_ok:
        print('\n'.join(l for l in (r.stdout + r.stderr).splitlines() if 'Error' in l or 'undefined' in l or 'FAILED' in l)[:3000])


if __name__ == '__main__':
    main()
