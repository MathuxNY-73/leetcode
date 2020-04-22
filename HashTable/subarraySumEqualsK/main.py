#! /usr/bin/env python3.7

from typing import List, Optional, Tuple

import sys
import collections
import itertools
import random
from queue import Queue

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        prefix_sum = 0
        sum_table = dict({0: 1})

        cnt = 0
        for x in nums:
            prefix_sum += x
            cnt += sum_table.get(prefix_sum - k, 0)

            if prefix_sum not in sum_table:
                sum_table[prefix_sum] = 0
            sum_table[prefix_sum] += 1


        return cnt

def main():
    T = int(input())
    print(T)
    for t in range(T):
        _, k = tuple(map(int, input().split()))

        nums = list(map(int, input().split()))
        print(f"New case with k={k} and nums={nums}")
        res = Solution().subarraySum(nums, k)

        print(res)


if __name__ == "__main__":
    main()
