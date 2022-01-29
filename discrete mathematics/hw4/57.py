#!/usr/bin/env sage

from sage.all import *
from functools import lru_cache
import math


@lru_cache
def fibonacci(n):
    if n in (0, 1):
        return n
    return fibonacci(n-1) + fibonacci(n-2)


def helper(n: int, ks: list[int]):
    total = sum(ks)
    res = 0
    if total == n:
        return math.prod(map(fibonacci, ks))
    for new_k in range(1, n - total + 1):
        ks.append(new_k)
        res += helper(n, ks)
        ks.pop()
    return res


seq = []
for n in range(1, 20):
    seq.append(helper(n, []))

print(oeis(seq))
