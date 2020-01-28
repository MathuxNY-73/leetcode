#!/usr/bin/env python3.6

from typing import List

import sys
import collections
import itertools
import random

class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        dp = []
        numb = []

        for i, n in enumerate(nums):
            dp.append(0)
            numb.append(1)
            for j in reversed(range(0,i)):
                if nums[j] < n:
                    if dp[j] > dp[i]:
                        dp[i] = dp[j]
                        numb[i] = numb[j]
                    elif dp[j] == dp[i]:
                        numb[i] += numb[j]
            dp[i] += 1

        print(dp)
        print(numb)
        m = max(dp)
        return sum([numb[i] for i, n in enumerate(dp) if n == m])


def main():
    lines = []
    for line in sys.stdin:
        lines.append(line.rstrip('\n'))

    T = int(lines.pop(0))

    for t in range(0,T):
        _ = int(lines.pop(0))
        nums = [int(x) for x in lines.pop(0).split()]
        res = Solution().findNumberOfLIS(nums)
        print(res)

if __name__ == "__main__":
    print("Hello World!")
    main()
