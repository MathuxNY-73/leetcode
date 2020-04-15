#!/usr/bin/env python3

from typing import List
import sys
import collections
import itertools

class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        n = len(coordinates)
        if n <= 1:
            return False

        i = 1
        while i < n and coordinates[i][0] == coordinates[0][0]:
            i += 1

        if i == n:
            return True;

        a = (coordinates[i][1] - coordinates[0][1]) / (coordinates[i][0] - coordinates[0][0])
        b = coordinates[0][1] - a * coordinates[0][0]

        for p in coordinates[1:]:
            if p[1] != a * p[0] + b:
                return False

        return True

lines = []
for line in sys.stdin:
    lines.append(line.rstrip('\n'))

T = int(lines.pop(0))

for t in range(0,T):
    N = int(lines.pop(0))
    print("Hello")
    points = [[int(x) for x in lines.pop(0).split()] for n in range(0,N)]
    res = Solution().checkStraightLine(points)
    print(res)

if __name__ == "__main__":
    print("Hello World!")
