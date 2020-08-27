#! /usr/bin/env python3.7

from typing import List, Optional, Tuple

import sys
import collections
import itertools
import random
from queue import Queue

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        freq = {}

        res = 0
        l = 0
        r = 0
        while r < len(s):
            if s[r] in freq:
                l = max(freq[s[r]], l)
            res = max(res, r - l + 1)
            freq[s[r]] = r + 1
            r += 1
        return res


def main():
    T = int(input())
    for t in range(T):
        _ = int(input())
        s = str(input())

        res = Solution().lengthOfLongestSubstring(s)

        print(res)


if __name__ == "__main__":
    main()
