#!/usr/bin/env python3

from typing import List
import sys
import collections
import itertools
import math
import heapq

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        m_ind = {}
        n = len(nums)

        for i in range(n):
            comp = target - nums[i]
            if comp in m_ind and m_ind[comp] != i:
                return [i, m_ind[comp]]
            m_ind[nums[i]] = i

        return []


def main() -> None:
    T = int(input())

    for t in range(T):
        N, target = tuple(map(int, input().split()))
        nums = list(map(int, input().split()))
        res = Solution().twoSum(nums, target)
        print(res)

if __name__ == "__main__":
   main()
