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
                            xx = max(0, min(x + xp, len(board) - 1))
                            yy = max(0, min(y + yp, len(row) - 1))
                            if board[xx][yy] == "O" and (xx, yy) not in seen:
                                seen.add((xx, yy))
                                group.append((xx, yy))
                                q.put((xx, yy))

                    if min_i > 0 and max_i < len(board) - 1 and min_j > 0 and max_j < len(row) - 1:
                        for x, y in group:
                            board[x][y] = "X"

    def solveFaster(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        dx = [1 , 0, -1, 0]
        dy = [0, 1, 0, -1]

        if not board or not board[0]:
            return

        rows = len(board)
        cols = len(board[0])

        from itertools import product
        borders = list(product(range(0, rows), [0, cols - 1])) + \
            list(product([0, rows - 1], range(0, cols)))

        for i,j in borders:
            if board[i][j] == 'O':
                q = Queue()
                q.put((i, j))

                while not q.empty():
                    x, y = q.get()
                    board[x][y] = 'E'

                    if board[x][y] != 'O':
                        continue

                    board[x][y] = 'E'

                    for xp, yp in zip(dx, dy):
                        xx = max(0, min(x + xp, rows - 1))
                        yy = max(0, min(y + yp, cols - 1))
                        q.put((xx, yy))

        for i in range(rows):
            for j in range(cols):
                if board[i][j] != 'X':
                    board[i][j] = 'O' if board[i][j] == 'E' else 'X'


def main():
    T = int(input())
    for t in range(T):
        N, M = tuple(map(int ,input().split()))

        board = [[c for c in str(input())] for _ in range(N)]
        Solution().solveFaster(board)

        for row in board:
            for cell in row:
                print(cell, end="")
            print()


if __name__ == "__main__":
    main()
