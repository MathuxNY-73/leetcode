#!/usr/bin/env python3

from typing import List
import sys
import collections
import itertools

class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        

    def addNum(self, num: int) -> None:
        

    def findMedian(self) -> float:


lines = []
for line in sys.stdin:
    lines.append(line.rstrip('\n'))

T = int(lines.pop(0))

for t in range(0,T):
    N = int(lines.pop(0))
    print("Hello")
    points = [[int(x) for x in lines.pop(0).split()] for n in range(0,N)]
    res = Solution().minAreaFreeRect(points)
    obj = MedianFinder()
    print(res)

if __name__ == "__main__":
    print("Hello World!")
