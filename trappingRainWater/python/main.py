#!/usr/bin/env python3.6

from typing import List, Optional, Tuple

import sys
import collections
import itertools
import random
from queue import PriorityQueue
import numpy as np

class Solution:
    def trap(self, height: List[int]) -> int:
        s = len(height)
        if s == 0:
            return 0

        q = PriorityQueue()
        seen = set()

        height_with_water = list(height)

        for i, h in enumerate(height):
            q.put((h, i))

        sum = 0

        while not q.empty():
            h, idx = q.get()
            if idx in seen:
                continue

            seen.add(idx)

            i = idx - 1
            while i >= 0 and height[i] <= h:
                seen.add(i)
                i -= 1
            if i == -1:
                continue

            max_l = height[i]
            max_l_i = i

            i = idx + 1
            while i < s and height[i] <= h:
                seen.add(i)
                i += 1
            if i == s:
                continue
            max_r = height[i]
            max_r_i = i

            max_h = min(max_l, max_r);
            for k in range(max_l_i + 1,max_r_i):
                height_with_water[k] = max_h

        return (np.array(height_with_water) - np.array(height)).sum()

def main():
    lines = []
    for line in sys.stdin:
        lines.append(line.rstrip('\n'))

    T = int(lines.pop(0))

    for t in range(0,T):
        _ = int(lines.pop(0))
        heights = [int(x) for x in lines.pop(0).split()]
        res = Solution().trap(heights)
        print(res)

if __name__ == "__main__":
    print("Hello World!")
    main()
