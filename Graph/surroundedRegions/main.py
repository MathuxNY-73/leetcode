#! /usr/bin/env python3.7

from typing import List, Optional, Tuple

import sys
import collections
import itertools
import random
from queue import Queue


class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        dx = [1 , 0, -1, 0]
        dy = [0, 1, 0, -1]

        seen = set()

        for i, row in enumerate(board):
            for j, cell in enumerate(row):
                if cell == "O" and (i, j) not in seen:
                    seen.add((i, j))
                    q = Queue()
                    q.put((i, j))

                    group = [(i,j)]

                    max_i, min_i = 0, float("inf")
                    max_j, min_j = 0, float("inf")

                    while not q.empty():
                        x, y = q.get()
                        max_i = max(max_i, x)
                        min_i = min(min_i, x)
                        max_j = max(max_j, y)
                        min_j = min(min_j, y)
                       
                        for xp, yp in zip(dx, dy):
                            xx = max(0, min(x + xp, len(grid) - 1))
                            yy = max(0, min(y + yp, len(row) - 1))
                            if grid[xx][yy] == "O" and (xx, yy) not in seen:
                                seen.add((xx, yy))
                                group.append((xx, yy))
                                q.put((xx, yy))

                    if min_i > 0 and max_i < len(grid) - 1 and min_j > 0 and max_j < len(row) - 1:
                        for x, y in group:
                            grid[x][y] = "X"


def main():
    T = int(input())
    for t in range(T):
        N, M = tuple(map(int ,input().split()))

        note, mag = tuple(input().split())
        res = Solution().canConstruct(note, mag)

        print(res)


if __name__ == "__main__":
    main()
