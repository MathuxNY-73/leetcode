#! /usr/bin/env python3.7

from typing import List, Optional, Tuple

import sys
import collections
import itertools
import random
from queue import Queue

class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        hash_table = collections.Counter(magazine)

        for x in ransomNote:
            if hash_table[x] <= 0:
                return False
            else:
                hash_table[x] -= 1

        return True

def main():
    T = int(input())
    for t in range(T):
        N, M = tuple(map(int ,input().split()))

        note, mag = tuple(input().split())
        res = Solution().canConstruct(note, mag)

        print(res)


if __name__ == "__main__":
    main()
