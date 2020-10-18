#! /usr/bin/env python3.7

from typing import List, Optional, Tuple

import sys
import collections
import itertools
import random
from queue import Queue

class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        starts = [(i[0], idx) for idx, i in enumerate(intervals)]
        starts.sort()

        def binSearch(s: int) -> int:
            l = 0
            r = len(starts)

            while l < r:
                m = l + ((r - l) >> 1)
                if s > starts[m][0]:
                    l = m + 1
                else:
                    r = m
            return -1 if l == len(starts) else starts[l][1]

        return [binSearch(i[1]) for i in intervals]


def main():
    T = int(input())
    for t in range(T):
        N = int(input())
        intervals = [list(map(int, input().split())) for _ in range(N)]

        res = Solution().findRightInterval(intervals)

        print(res)


if __name__ == "__main__":
    main()
