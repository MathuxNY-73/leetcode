#! /usr/bin/env python3.7

from typing import List, Optional, Tuple

import sys
import collections
import itertools
import random
from queue import Queue

class Solution:
    def possibleBipartition(self, N: int, dislikes: List[List[int]]) -> bool:
        side = [-1 for _ in range(N + 1)]
        is_bipartite = True
        for i in range(1, N + 1):
            if side[i] == -1:
                q = Queue()
                q.put(i)
                side[i] = 0
                while not q.empty():
                    cur = q.get()
                    for a in [l[1] for l in dislikes if l[0] == cur]:
                        if side[a] == -1:
                            side[a] = side[cur] ^ 1
                            q.put(a)
                        else:
                            is_bipartite &= bool(side[cur] ^ side[a])

        return is_bipartite

def main():
    T = int(input())
    for t in range(T):
        N = int(input())
        size = int(input())
        dislikes = [list(map(int, input().split())) for _ in range(size)]

        res = Solution().possibleBipartition(N, dislikes)

        print(res)


if __name__ == "__main__":
    main()
