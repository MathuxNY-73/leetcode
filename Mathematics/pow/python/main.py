#! /usr/bin/env python3.7

from typing import List, Optional, Tuple

import sys
import collections
import itertools
import random
from queue import Queue


class Solution:
    def myPow(self, x: float, n: int) -> float:
        res = 1
        if n < 0:
            x = 1 / x
            n = -n

        while n:
            if n & 1:
                res *= x
            x = (x * x)
            n >>= 1

        return res


def main():
    T = int(input())
    for t in range(T):
        N, K = tuple(map(float ,input().split()))

        res = Solution().myPow(N, int(K))
        print(f"{res}")


if __name__ == "__main__":
    main()
