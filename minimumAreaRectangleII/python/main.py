#!/usr/bin/env python3

from typing import List
import sys

class Solution:
    def minAreaFreeRect(self, points: List[List[int]]) -> float:
        for p in points:
            print(p)

lines = []
for line in sys.stdin:
    lines.append(line.rstrip('\n'))

T = int(lines.pop(0))

for t in range(0,T):
    N = int(lines.pop(0))
    print("Hello")
    points = [[int(x) for x in lines.pop(0).split()] for n in range(0,N)]
    Solution().minAreaFreeRect(points)

if __name__ == "__main__":
    print("Hello World!")
