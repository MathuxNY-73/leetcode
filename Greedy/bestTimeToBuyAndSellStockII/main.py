#! /usr/bin/env python3.7

from typing import List, Optional, Tuple

import sys
import collections
import itertools
import random
from queue import PriorityQueue
import numpy as np

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) < 2:
            return 0

        res = 0
        for i in range(1, len(prices)):
            if prices[i] > prices[i - 1]:
                res += (prices[i] - prices[i - 1])
        return res
       

def main():
    T = int(input())
    for t in range(T):
        N = int(input())

        prices = list(map(int, input().split()))
        res = Solution().maxProfit(prices)

        print(res)


if __name__ == "__main__":
    main()
