#! /usr/bin/env python3.7

from typing import List, Optional, Tuple

import sys
import collections
import itertools
import random
from queue import Queue

class Solution:
    def prisonAfterNDays(self, cells: List[int], N: int) -> List[int]:
        n = 14 if N % 14 == 0 else N % 14;
        tmp = list(cells)

        for _ in range(0, n):
            tmp[0] = 0
            tmp[len(cells) - 1] = 0
            for i in range(1, len(cells) - 1):
                if cells[i - 1] == cells[i + 1]:
                    tmp[i] = 1
                else:
                    tmp[i] = 0
            cells, tmp = tmp, cells
        return cells

    def prisonAfterNDaysHashTable(self, cells: List[int], N: int) -> List[int]:
        seen = []
        tmp = list(cells)

        while N > 0:
            N -= 1
            tmp[0] = 0
            tmp[len(cells) - 1] = 0
            for i in range(1, len(cells) - 1):
                if cells[i - 1] == cells[i + 1]:
                    tmp[i] = 1
                else:
                    tmp[i] = 0
            if len(seen) > 0 and tmp == seen[0]:
                return seen[N % len(seen)]
            else:
                seen.append(list(tmp))

            cells, tmp = tmp, cells

        return cells


def main():
    T = int(input())
    print(T)
    for t in range(T):
        cells = list(map(int, input().split()))
        N = int(input())
        res = Solution().prisonAfterNDaysHashTable(cells, N)

        print(res)


if __name__ == "__main__":
    main()
