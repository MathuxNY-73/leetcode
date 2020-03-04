#!/usr/bin/env python3.6

from typing import List, Optional, Tuple

import sys
import collections
import itertools
import random
from queue import Queue

class Solution:
    def trap(self, height: List[int]) -> int:
        s = len(height)
        if s == 0:
            return 0

        i = 0
        while i < s and height[i] == 0:
            i += 1

        if i == s:
            return 0

        sum = 0
        #print(f"i at the beginning is {i}")
        while i < s:
            t_s = 0
            for j in range(i+1, s):
                if height[i] <= height[j]:
                    sum += t_s
                    t_s = 0
                    #print(f"At {j} sum is {sum}")
                    i = j
                else:
                    #print(f"At {j} with i={i} t_s={t_s} and add {height[i] - height[j]}")
                    t_s += (height[i] - height[j])
            i += 1

        return sum

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
