#!/usr/bin/env python3.6

from typing import List

import sys
import collections
import itertools
import random
import numpy as np
from fractions import Fraction
import heapq

class Solution:
    def mincostToHireWorkers(self, quality: List[int], wage: List[int], K: int) -> float:
        r_w_q = [(Fraction(w,q), w, q) for w, q in zip(wage, quality)]
        r_w_q.sort()

        sum = 0
        container = []
        res = float('inf')
        for r, w, q in r_w_q:
            heapq.heappush(container, -q)
            sum += q
            if len(container) > K:
                sum += heapq.heappop(container)
            if len(container) == K:
                res = min(res, sum * r)
        return float(res)

def main():
    lines = []
    for line in sys.stdin:
        lines.append(line.rstrip('\n'))

    T = int(lines.pop(0))

    for t in range(0,T):
        _, k = (int(x) for x in lines.pop(0).split())
        quality = [int(x) for x in lines.pop(0).split()]
        wage = [int(x) for x in lines.pop(0).split()]
        res = Solution().mincostToHireWorkers(quality, wage, k)

        print(res)

if __name__ == "__main__":
    print("Hello World!")
    main()
