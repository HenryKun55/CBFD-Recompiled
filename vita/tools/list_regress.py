#!/usr/bin/env python3
"""What each part of a display list's reading costs, from ux0:data/conker/lists.csv (written with
ux0:data/conker/debug_listcsv present): the reader's time per list fitted, by least squares, to
what the list read (commands, vertices, triangles, state changes, texture loads...). No clock runs
inside the reader, so the costs are the real ones (as far as a linear model holds).

usage: vita/tools/list_regress.py lists.csv [--min-us N]
Needs numpy and scipy (uv run --with numpy --with scipy python ...).
"""
import argparse
import csv

import numpy as np
from scipy.optimize import nnls

# The fitted terms: a column of the CSV (scaled to a readable unit) and how it's shown.
TERMS = [
    ('cmds', 1, 'a command'),
    ('vtx', 1, 'a vertex'),
    ('vtx_loads', 1, 'a vertex load'),
    ('tris', 1, 'a triangle'),
    ('prepares', 1, 'a state change (prepare_draw)'),
    ('textures', 1, 'a texture decoded'),
    ('block_loads', 1, 'a LOADBLOCK'),
    ('block_bytes', 1024, 'a KB loaded'),
    ('tlut_loads', 1, 'a LOADTLUT'),
    ('matrices', 1, 'a matrix'),
    ('ctx_pushes', 1, 'a vertex context'),
]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('csv')
    ap.add_argument('--min-us', type=int, default=1000, help='lists shorter than this are left out (loading screens)')
    a = ap.parse_args()
    rows = [r for r in csv.DictReader(open(a.csv)) if int(r['read_us']) >= a.min_us]
    if not rows:
        raise SystemExit('no lists')
    terms = [t for t in TERMS if any(int(r[t[0]]) for r in rows)]
    X = np.array([[1.0] + [int(r[t[0]]) / t[1] for t in terms] for r in rows])
    y = np.array([float(r['read_us']) for r in rows])
    # Non-negative (nothing costs less than nothing): terms that move together otherwise trade
    # signs. The fixed part's column is left free of that by fitting it as one more term.
    coef, _ = nnls(X, y)
    fit = X @ coef
    r2 = 1 - ((y - fit) ** 2).sum() / ((y - y.mean()) ** 2).sum()
    heavy = X[y.argmax()]
    print('%d lists, read %.1f ms on average (heaviest %.1f), fit R^2 %.3f' % (len(rows), y.mean() / 1000, y.max() / 1000, r2))
    print('%-32s %10s %12s %12s' % ('term', 'us each', 'avg ms/list', 'heaviest ms'))
    print('%-32s %10s %12.2f %12.2f' % ('fixed a list', '', coef[0] / 1000, coef[0] / 1000))
    for i, t in enumerate(terms, 1):
        print('%-32s %10.3f %12.2f %12.2f' % (t[2], coef[i], coef[i] * X[:, i].mean() / 1000, coef[i] * heavy[i] / 1000))


if __name__ == '__main__':
    main()
