#!/usr/bin/env sage

from sage.all import *
from sage.graphs.graph_coloring import numbers_of_colorings, number_of_n_colorings

for i in range(1, 100):
    print(i)
    less, more, equal = False, False, False
    for g in graphs(i):
        dom = len(g.dominating_set())
        cov = len(g.vertex_cover())
        if dom < cov:
            less = True
        if dom > cov:
            more = True
        if dom == cov:
            equal = True
        if less and more and equal:
            break
    if not less:
        print('less')
    if not more:
        print('more')
    if not equal:
        print('equal')
