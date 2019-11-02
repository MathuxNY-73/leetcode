#!/usr/bin/env python3

from typing import List
import sys
import collections
import itertools

class Solution:
    def minAreaFreeRect(self, points: List[List[int]]) -> float:
        points = [complex(*z) for z in points]
        d = collections.defaultdict(list)
        for P, Q in itertools.combinations(points, 2):
            center = (P + Q) / 2.0
            radius = abs(center - P)
            d[radius, center].append(P)

        res = float("inf")
        for (r, c), cand in d.items():
            for P, Q in itertools.combinations(cand, 2):
                res = min(res, abs(P - Q) * abs(P - (2*c - Q)))

        return res if res < float("inf") else 0

lines = []
for line in sys.stdin:
    lines.append(line.rstrip('\n'))

T = int(lines.pop(0))

for t in range(0,T):
    N = int(lines.pop(0))
    print("Hello")
    points = [[int(x) for x in lines.pop(0).split()] for n in range(0,N)]
    res = Solution().minAreaFreeRect(points)
    print(res)

if __name__ == "__main__":
    print("Hello World!")
