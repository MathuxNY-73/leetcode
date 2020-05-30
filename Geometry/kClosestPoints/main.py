#!/usr/bin/env python3

from typing import List
import sys
import collections
import itertools
import math
import heapq

class Solution:
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        pool = []
        for x, y in list(map(tuple, points)):
            d = -(x * x + y * y)
            if len(pool) < K:
                heapq.heappush(pool, (d, (x,y)))
            elif pool[0][0] < d:
                heapq.heappushpop(pool, (d, (x, y)))
        return [[p[0], p[1]] for _, p in pool]

T = int(input())

for t in range(0,T):
    N, K = tuple(map(int, input().split()))
    points = [list(map(int, input().split())) for n in range(0,N)]
    res = Solution().kClosest(points, K)
    print(res)

if __name__ == "__main__":
    print("Hello World!")
