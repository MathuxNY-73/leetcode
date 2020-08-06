#!/usr/bin/env python3

from typing import List
import sys
import collections
import itertools
import math
import heapq

class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        s = set()
        res = []
        for n in nums:
            if n not in s:
                s.add(n)
            else:
                res.append(n)

        return res


def main():
    T = int(input())

    for t in range(0,T):
        N = int(input())
        nums = list(map(int, input().split()))
        res = Solution().findDuplicates(nums)
        print(res)

if __name__ == "__main__":
    main()
