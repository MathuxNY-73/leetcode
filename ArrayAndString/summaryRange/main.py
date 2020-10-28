#!/usr/bin/env python3

from typing import List
import sys
import collections
import itertools
import math
import heapq

class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        n = len(nums)
        res = []

        if n == 0: return res

        i = 0
        while i < n:
            j = i
            while i + 1 < n and nums[i + 1] == nums[i] + 1:
                i += 1
            s = str(nums[j])
            if j != i:
                s += f"->{nums[i]}"
            res.append(s)

            i += 1

        return res

def main() -> None:
    T = int(input())

    for t in range(T):
        N = int(input())
        nums = list(map(int, input().split()))
        res = Solution().summaryRanges(nums)
        print(res)

if __name__ == "__main__":
   main()
