#!/usr/bin/env python3.6

from typing import List

import sys
import collections
import itertools
import random

class Solution:
    def __init__(self, N: int, blacklist: List[int]) -> None:
        b_len = len(blacklist)
        self._m = N - b_len

        blacklist.sort()

        i = 0
        while i < b_len and blacklist[i] < self._m:
            i += 1

        j = self._m; k = 0

        self._whitelist = {}
        while j < N:
            while i < b_len and blacklist[i] == j:
                i += 1; j += 1
            self._whitelist[blacklist[k]] = j
            k += 1
            j += 1

        print(self._whitelist)

    def pick(self) -> int:
        r = random.randint(0, self._m - 1)
        #print('Pick is {}'.format(r))
        return self._whitelist.get(r, r)

class SolutionBinarySearch:
    def __init__(self, N: int, blacklist: List[int]) -> None:
        self._blacklist = blacklist
        self._blacklist.sort()
        self._b_size = len(self._blacklist)
        self._n = N

    def bin_search(self, k: int) -> int:
        i = 0; j = self._b_size - 1
        while i < j:
            m = (i + j + 1) // 2
            c = self._blacklist[m] - m
            if c <= k:
                i = m
            else:
                j = m - 1

        if i == j and self._blacklist[i] - i <= k:
            return k + i + 1
        else:
            return k

    def pick(self) -> int:
        r = random.randint(0, self._n - self._b_size - 1)
        return self.bin_search(r)


def main():
    lines = []
    for line in sys.stdin:
        lines.append(line.rstrip('\n'))

    T = int(lines.pop(0))

    for t in range(0,T):
        N, blacklist_size = (int(x) for x in lines.pop(0).split())
        blacklist = []
        if blacklist_size > 0:
            blacklist = [int(x) for x in lines.pop(0).split()]
        print(blacklist)
        n_pick = int(lines.pop(0))
        res = SolutionBinarySearch(N, blacklist)

        for _ in range(n_pick):
            print(res.pick())

if __name__ == "__main__":
    print("Hello World!")
    main()
