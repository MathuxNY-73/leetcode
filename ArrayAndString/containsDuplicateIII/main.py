#! /usr/bin/env python3.7

from typing import List, Optional, OrderedDict, Tuple

import sys
import collections
import itertools
import random
import bisect
from queue import Queue

class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], k: int, t: int) -> bool:
        n = len(nums)
        if n == 0 or k <= 0 or t < 0: return False

        d = OrderedDict()

        for i, e in enumerate(nums):
            pool = [num[0] for num in d.keys()]
            pool.sort()
            print(f"Keys are: {' '.join(map(str, pool))}")
            l_b = bisect.bisect_left(pool, e)

            print(f"Foud lower bound {l_b} for e={e} at i={i}")
            if l_b < len(pool) and pool[l_b] <= e + t: return True
            u_b = bisect.bisect_right(pool, e - t - 1)

            print(f"Foud upper bound {u_b} for e={e - t - 1} at i={i}")
            if u_b < len(pool) and pool[u_b] >= e - t and pool[u_b] <= e: return True

            if len(d) == k:
                d.popitem(last=False)

            d[(e, i)] = i

        return False


def main():
    T = int(input())
    for t in range(T):
        N, K, T = tuple(map(int, input().split()))
        nums = list(map(int, input().split()))

        res = Solution().containsNearbyAlmostDuplicate(nums, K, T)

        print(res)


if __name__ == "__main__":
    main()
