#!/usr/bin/env python3
"""Puts matched candidates (build/cand/FUNC.c) in place of their #pragma GLOBAL_ASM.

    python3 integrate_matches.py FUNC...

Each candidate replaces its function's pragma line in the linked source file. Run the
full build afterwards (make; build/conker.us.bin: OK) to check the whole ROM.
"""
import glob
import re
import sys

for func in sys.argv[1:]:
    cand = open(f'build/cand/{func}.c').read().strip('\n') + '\n'
    if '#pragma GLOBAL_ASM' in cand:
        print(f'{func}: the candidate has a #pragma GLOBAL_ASM (left out)', file=sys.stderr)
        continue
    pragma_re = re.compile(r'^[ \t]*#pragma GLOBAL_ASM\("asm/nonmatchings/[^"]*/' + re.escape(func) + r'\.s"\)[ \t]*$', re.M)
    done = False
    for path in glob.glob('src/**/*.c', recursive=True):
        if '/game/' in path.replace('\\', '/'):
            continue
        text = open(path, encoding='utf-8', errors='replace').read()
        if len(pragma_re.findall(text)) == 1:
            open(path, 'w', newline='\n').write(pragma_re.sub(lambda m: cand.rstrip('\n'), text))
            print(f'{func}: {path}')
            done = True
            break
    if not done:
        print(f'{func}: pragma not found', file=sys.stderr)
