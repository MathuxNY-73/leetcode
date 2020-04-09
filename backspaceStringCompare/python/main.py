#! /usr/bin/env python3.7

from typing import List, Optional, Tuple

import sys
import collections
import itertools
import random
from queue import PriorityQueue

class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        i = len(S) - 1
        j = len(T) - 1

        while i >= 0 or j >= 0:
            bksp = 0
            while i >= 0:
                if S[i] == '#':
                    bksp += 1; i -= 1
                elif bksp > 0:
                    bksp -= 1; i -= 1
                else:
                    break

            bksp = 0
            while j >= 0:
                if T[j] == '#':
                    bksp += 1; j -= 1
                elif bksp > 0:
                    bksp -= 1; j -= 1
                else:
                    break
            if i >= 0 and j >= 0 and S[i] != T[j] :
                return False

            if (i >= 0) != (j >= 0) :
                return False

            i -= 1; j -= 1

        return True

def main():
    T = int(input())
    for t in range(T):
        S_size, T_size = tuple(map(int, input().split()))


        S, N = tuple(map(str, input().split()))
        res = Solution().backspaceCompare(S, N)

        print(res)


if __name__ == "__main__":
    main()
