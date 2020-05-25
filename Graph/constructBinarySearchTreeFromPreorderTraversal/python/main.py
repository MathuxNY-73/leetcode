#! /usr/bin/env python3.7

from typing import List, Optional, Tuple

import sys
import collections
import itertools
import random
from queue import Queue

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:

    def buildBst(self, preorder: List[int], parent_val: int) -> TreeNode:
        if self.i >= len(preorder) or preorder[self.i] >= parent_val:
           return None

        root = TreeNode(preorder[self.i])
        self.i+=1
        root.left = self.buildBst(preorder, root.val)
        root.right = self.buildBst(preorder, parent_val)

        return root

    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        self.i = 0
        return self.buildBst(preorder, sys.maxsize)


def main():
    T = int(input())
    for t in range(T):
        N = int(input())

        tree = list(map(int, input().split()))
        q = Queue()

        res = Solution().bstFromPreorder(tree)
        q.put(res)

        println = lambda x: print(f"{x} ", end='', flush=True)

        while not q.empty():
            cur = q.get()

            if cur:
                println(cur.val)
                q.put(cur.left)
                q.put(cur.right)
            else:
                println("N")

        print()


if __name__ == "__main__":
    main()
