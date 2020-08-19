#!/usr/bin/env python3

from typing import List
import sys
import collections
import itertools
import math
import heapq

class Solution:
    def toGoatLatin(self, S: str) -> str:
        def proc(idx, w):
            if w[0] not in 'aeiouAEIOU':
                w = w[1:] + w[0]
            return w + "ma" + "a" * idx
        return ' '.join(proc(i, w) for i, w in enumerate(S.split(), 1))



def main():
    T = int(input())

    for t in range(0,T):
        N = int(input())
        res = Solution().toGoatLatin(input())
        print(res)

if __name__ == "__main__":
    main()
