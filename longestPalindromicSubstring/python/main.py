#!/usr/bin/env python3.6

from typing import List, Optional, Tuple

import sys
import collections
import itertools
import random
from queue import Queue

class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s) == 0:
            return ""

        lps = s[0]
        #print("i ranges: {}".format(list(reversed(range(len(s))))))
        for i in reversed(range(len(s))):
            #print("k ranges: {}".format(list(range(i))))
            for k in range(i):
                if (i - k  + 1) > len(lps) and self.checkPalindrome(s[k:(i+1)]):
                    lps = s[k:(i+1)]
        return lps


    def checkPalindrome(self, s: str) -> bool:
        for i in range(len(s) // 2):
            if s[i] != s[len(s) - 1 - i]:
                return False
        return True

def main():
    lines = []
    for line in sys.stdin:
        lines.append(line.rstrip('\n'))

    T = int(lines.pop(0))

    for t in range(0,T):
        _, s = tuple(lines.pop(0).split())
        res = Solution().longestPalindrome(s)
        print(res)

if __name__ == "__main__":
    print("Hello World!")
    main()
