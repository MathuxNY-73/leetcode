#! /usr/bin/env python3.7

from typing import List, Optional, Tuple

import sys
import collections
import itertools
import random
from queue import Queue
import heapq

class Solution:
    def networkDelayTime(self, times: List[List[int]], N: int, K: int) -> int:
        colors = [0 for _ in range(N + 1)]
        colors[0] = 1

        adj = {}
        for i in range(N + 1):
            adj[i] = []

        for edge in times:
            adj[edge[0]].append((edge[1], edge[2]))

        pool = [(0, K)]

        max_time = 0

        while len(pool):
            c, n = heapq.heappop(pool)

            if colors[n] == 1:
                continue

            max_time = max(c, max_time)

            colors[n] = 1

            for to, w in adj[n]:
                heapq.heappush(pool, (c + w, to))

        for c in colors:
            if c == 0:
                return -1

        return max_time


def main():
    T = int(input())
    for t in range(T):
        N, K = tuple(map(int, input().split()))
        E = int(input())

        times = [tuple(map(int, input().split())) for _ in range(E)]

        res = Solution().networkDelayTime(times, N, K)

        print(res)

        

if __name__ == "__main__":
    main()
