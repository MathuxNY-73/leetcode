#!/usr/bin/env python3.6

from typing import List, Optional, Tuple

import sys
import collections
import itertools
import random
from queue import PriorityQueue
import numpy as np

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals) == 0:
            return []

        start = [i[0] for i in intervals]
        end = [i[1] for i in intervals]

        start.sort()
        end.sort()

        res = []
        i = 1; s = start[0]
        while i <= len(start):
            if i == len(start):
                res.append([s, end[i - 1]])
            elif start[i] > end[i-1]:
                res.append([s, end[i - 1]])
                s = start[i]

            i+= 1

        return res

def main():
    lines = []
    for line in sys.stdin:
        lines.append(line.rstrip('\n'))

    T = int(lines.pop(0))

    for t in range(0,T):
        n = int(lines.pop(0))
        A = [[int(x) for x in l.split()] for l in (lines.pop(0) for _ in range(n))]
        print(A)
        res = Solution().merge(A)
        print(res)

if __name__ == "__main__":
    print("Hello World!")
    main()
