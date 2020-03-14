#!/usr/bin/env python3.6

from typing import List, Optional, Tuple

import sys
import collections
import itertools
import random
from queue import PriorityQueue
import numpy as np

class Solution:
    def peakIndexInMountainArray(self, A: List[int]) -> int:
        for i, e in enumerate(A):
            if i > 0 and i < len(A) - 1 and A[i] > A[i-1] and A[i] > A[i+1]:
                return i

def main():
    lines = []
    for line in sys.stdin:
        lines.append(line.rstrip('\n'))

    T = int(lines.pop(0))

    for t in range(0,T):
        _ = int(lines.pop(0))
        A = [int(x) for x in lines.pop(0).split()]
        res = Solution().peakIndexInMountainArray(A)
        print(res)

if __name__ == "__main__":
    print("Hello World!")
    main()
