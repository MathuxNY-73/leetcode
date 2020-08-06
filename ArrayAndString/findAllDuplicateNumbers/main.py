#!/usr/bin/env python3

from typing import List
import sys
import collections
import itertools
import math
import heapq

class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        res = []
        for n in nums:
            if nums[abs(n) - 1] < 0:
                res.append(abs(n))
            else:
                nums[abs(n) - 1] *= -1
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
