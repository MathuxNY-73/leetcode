#!/usr/bin/env python3.6

from typing import List

import sys
import collections
import itertools
import random

class Solution:

    def backtrack(self, wordSquare: List[str], res: List[List[str]], index: int, words: List[str]):
        if index >= len(wordSquare[0]):
            res.append(wordSquare)
            return

        for w in words:
            elligible = True
            for i in range(index):
                if not w[i] == wordSquare[i][index]:
                    #print("Comparing {} with {} for word={} and wordSquare[{}]={} then elligible=False"
                    #      .format(w[i], wordSquare[i][index], w, i, wordSquare[i]))
                    elligible = False
            if elligible:
                #print("Adding word={} with elligible={}".format(w, elligible))
                self.backtrack(wordSquare + [w], res, index + 1, words)

    def wordSquares(self, words: List[str]) -> List[List[str]]:
        res = []
        for w in words:
            self.backtrack([w], res, 1, words)
        return res


def main():
    lines = []
    for line in sys.stdin:
        lines.append(line.rstrip('\n'))

    T = int(lines.pop(0))

    for t in range(0,T):
        _ = int(lines.pop(0))
        nums = [str(x) for x in lines.pop(0).split()]
        #print(nums)
        res = Solution().wordSquares(nums)
        print(res)

if __name__ == "__main__":
    print("Hello World!")
    main()
