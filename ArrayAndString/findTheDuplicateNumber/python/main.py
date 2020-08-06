#!/usr/bin/env python3

from typing import List
import sys
import collections
import itertools
import math
import heapq

class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        tortoise = nums[0]
        hare = nums[0]

        while True:
            hare = nums[nums[hare]]
            tortoise = nums[tortoise]
            if hare == tortoise:
                break

        ptr1 = tortoise
        ptr2 = nums[0]

        while ptr1 != ptr2:
            ptr1 = nums[ptr1]
            ptr2 = nums[ptr2]

        return ptr1

def main():
    T = int(input())

    for t in range(0,T):
        N = int(input())
        nums = list(map(int, input().split()))
        res = Solution().findDuplicate(nums)
        print(res)

if __name__ == "__main__":
    main()
