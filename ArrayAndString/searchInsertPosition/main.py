#!/usr/bin/env python3

from typing import List
import sys
import collections
import itertools
import math
import heapq

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if len(nums) == 0:
            return 0

        l = 0
        r = len(nums)
        while l < r:
            m1 = l + (r - l) // 3
            m2 = l + 2 * ((r - l) // 3)
            if target <= nums[m1]:
                r = m1
            elif target <= nums[m2]:
                l = m1 + 1
                r = m2
            else:
                l = m2 + 1

        return r

T = int(input())

for t in range(0,T):
    N, K = tuple(map(int, input().split()))
    nums = list(map(int, input().split()))
    res = Solution().searchInsert(nums, K)
    print(res)

if __name__ == "__main__":
    print("Hello World!")
