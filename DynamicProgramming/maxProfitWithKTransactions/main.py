#! /usr/bin/env python3.7

from typing import List, Optional, Tuple

import sys
import collections
import itertools
import random
from queue import PriorityQueue

class Solution:

    def maxProfit(self, k: int, prices: List[int]) -> int:
        n = len(prices)
        if 2 * k >= n:
            res = 0
            for i in range(1, n):
                if prices[i] > prices[i - 1]:
                    res += prices[i] - prices[i - 1]
            return res
        else:
            dp = [0] * n
            for i in range(k):
                maxP = -prices[0]
                for j in range(1, n):
                    tmp = dp[j]
                    dp[j] = max(dp[j - 1], prices[j] + maxP)
                    maxP = max(maxP, tmp - prices[j])
            return dp[n - 1]


def main():
    T = int(input())
    for t in range(T):
        N, K = tuple(map(int, input().split()))

        prices = list(map(int, input().split()))
        res = Solution().maxProfit(K, prices)

        print(res)


if __name__ == "__main__":
    main()
