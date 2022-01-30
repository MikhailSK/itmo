#!/usr/bin/env sage

from sage.all import *
from tqdm import tqdm

cnt = 30
for g in tqdm(graphs(10)):
    if not g.is_connected():
        continue
    true_val = len(g.matching())
    n = 10
    new_g = Graph()
    new_g.add_vertices(range(n * 2))
    mat = g.adjacency_matrix()
    for i in range(n):
        for j in range(n):
            if mat[i][j] == 1:
                new_g.add_edge(i, j + n)
    other_val = len(new_g.matching())
    if other_val // 2 != true_val:
        print(g.matching())
        print(new_g.matching())
        g.export_to_file(f"counterexample_{cnt}.dot")
        new_g.export_to_file(f"counterexample2_{cnt}.dot")
        cnt += 1
