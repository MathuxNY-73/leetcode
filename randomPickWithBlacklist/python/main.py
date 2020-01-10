#!/usr/bin/env python3

from typing import List
import sys
import collections
import itertools

class Solution:
    def __init__(self, N: int, blacklist: List[int]):

    def pick(self) -> int:



lines = []
for line in sys.stdin:
    lines.append(line.rstrip('\n'))

T = int(lines.pop(0))

for t in range(0,T):
    N = int(lines.pop(0))
    points = [[int(x) for x in lines.pop(0).split()] for n in range(0,N)]
    res = Solution().minAreaFreeRect(points)
    print(res)

if __name__ == "__main__":
    print("Hello World!")
