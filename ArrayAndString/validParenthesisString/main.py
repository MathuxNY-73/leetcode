#! /usr/bin/env python3.7

from typing import List, Optional, Tuple

import sys
import collections
import itertools
import random
from queue import PriorityQueue

class Solution:
    def checkValidString(self, s: str) -> bool:
        hi, lo = 0, 0

        for c in s:
            lo += 1 if c == '(' else -1
            hi += 1 if c != ')' else -1
            if hi < 0: break
            lo = max(lo, 0)

        return lo == 0

   
    def checkValidStringStack(self, s: str) -> bool:
        left = []
        star = []

        for i,c in enumerate(s):
            if c == "(":
                left.append(i)
            elif c == "*":
                star.append(i)
            else:
                if len(left) != 0:
                    left.pop()
                elif len(star) != 0:
                    star.pop()
                else:
                    return False

        if len(left) > 0:
            if len(star) > 0 and left[-1] > star[-1]:
                return False
            elif len(star) == 0:
                return False
            else:
                while len(left) and len(star) > 0 and left[-1] < star[-1]:
                    star.pop()
                    left.pop()
                if len(left):
                    return False

        return True


def main():
    T = int(input())
    for t in range(T):
        _ = int(input())

        s = str(input())
        res = Solution().checkValidString(s)

        print(res)


if __name__ == "__main__":
    main()
