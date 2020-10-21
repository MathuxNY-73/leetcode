#! /usr/bin/env python3.7

from typing import List, Optional, Tuple

import sys
import collections
import itertools
import random
from queue import Queue


class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        ast = []

        res = []
        for a in asteroids:
            if a > 0:
                ast.append(a)
            else:
                while len(ast) > 0 and ast[-1] < -a:
                    ast = ast[:-1]
                if len(ast) > 0 and ast[-1] == -a:
                    ast = ast[:-1]
                elif len(ast) == 0:
                    res.append(a)
        for a in ast:
            res.append(a)

        return res


def main():
    T = int(input())
    for t in range(T):
        N = int(input())

        asteroids = list(map(int, input().split()))
        res = Solution().asteroidCollision(asteroids)

        print(res)


if __name__ == "__main__":
    main()
