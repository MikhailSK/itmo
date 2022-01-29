#!/usr/bin/env sage

from sage.all import *

for n in range(1, 6):
    print(n)
    for g in graphs(n):
        if not g.is_hamiltonian():
            continue
        if g.chromatic_number() < 1 + n / 2:
            g.export_to_file('smaller.dot')
        if g.chromatic_number() > 1 + n / 2:
            g.export_to_file('bigger.dot')
