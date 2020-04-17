#! /usr/bin/env python3.7

from typing import List, Optional, Tuple

import sys
import collections
import itertools
import random
from queue import Queue

class Solution:
    def __init__(self) -> None:
        self._dx = [1, 0, -1, 0]
        self._dy = [0, 1, 0, -1]

    def numIslands(self, grid: List[List[str]]) -> int:
        r = len(grid)
        if r == 0 or len(grid[0]) == 0:
            return 0

        c = len(grid[0])
        res = 0

        for i in range(r):
            for j in range(c):
                if grid[i][j] == '1':
                    res += 1
                    q = Queue()
                    q.put((i,j))

                    while not q.empty():
                        x, y = q.get()
                        grid[x][y] = str(res+1)
                        for k in range(4):
                            xx = x + self._dx[k]
                            yy = y + self._dy[k]

                            if min(xx,yy) < 0 or xx == r or yy == c:
                                continue
                            if grid[xx][yy] == '0':
                                continue
                            if grid[xx][yy] == '1':
                                q.put((xx,yy))
        return res

def main():
    T = int(input())
    for t in range(T):
        _, r = tuple(map(int, input().split()))

        grid = [list(map(str, input())) for _ in range(r)]
        res = Solution().numIslands(grid)

        print(res)


if __name__ == "__main__":
    main()
