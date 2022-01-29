#!/usr/bin/env sage

from sage.all import *

i = 4
while True:
    for n in range(50, 100, 2):
        g = graphs.RandomRegular(3, n)
        if len(g.bridges()) < 3:
            # print('nah')
            continue
        print('ye')
        if not g.has_perfect_matching():
            g.export_to_file(f"106_{i}.dot")
            i += 1
