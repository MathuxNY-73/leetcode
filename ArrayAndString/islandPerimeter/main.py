#!/usr/bin/env python3

from typing import List
import sys
import collections
import itertools
import math
import heapq

class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        n = len(grid)
        if not n:
            return 0
        m = len(grid[0])
        if not m:
            return 0

        res = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:

                    res += 4
                    res -=  2 * int(i > 0 and grid[i - 1][j] == 1)
                    res -=  2 * int(j > 0 and grid[i][j -1] == 1)

        return res


def main():

    T = int(input())

    for t in range(0,T):
        N, M = tuple(map(int, input().split()))
        grid = [list(map(int, input().split())) for _ in range(M)]
        res = Solution().islandPerimeter(grid)
        print(res)


if __name__ == "__main__":
    main()
