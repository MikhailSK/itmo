#!/usr/bin/env sage

from sage.all import *
from sage.graphs.graph_coloring import numbers_of_colorings, number_of_n_colorings

for i in range(1, 4):
    print(i)
    for g in graphs(i):
        dom = len(g.dominating_set())
        ind = len(g.independent_set())
        if dom < ind:
            g.export_to_file("dom_ind.dot")
        # if g.size() == i * (i-1) // 2:
        #     continue
        # if number_of_n_colorings(g, 3) != 6:
        #     continue
        # g.export_to_file("result.dot")
        # exit(0)
