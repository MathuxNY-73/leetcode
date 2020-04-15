#! /usr/bin/env python3.7

from typing import List, Optional, Tuple

import sys
import collections
import itertools
import random
from queue import PriorityQueue

class Solution:
   def maxProfit(self, prices: List[int]) -> int:
        min_p = float("inf")
        max_profit = 0

        for x in prices:
            min_p = min(min_p, x)
            max_profit = max(max_profit, x - min_p)

        return max_profit
       

def main():
    T = int(input())
    for t in range(T):
        N = int(input())

        prices = list(map(int, input().split()))
        res = Solution().maxProfit(prices)

        print(res)


if __name__ == "__main__":
    main()
