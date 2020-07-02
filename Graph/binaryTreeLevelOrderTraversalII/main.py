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

    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        res = []
        if not root:
            return res

        q = Queue()
        q.put((root, 0))

        while not q.empty():
            cur, lev = q.get()
            if lev == len(res):
                res.append([cur.val])
            else:
                res[lev].append(cur.val)

            if cur.left:
                q.put((cur.left, lev + 1))
            if cur.right:
                q.put((cur.right, lev + 1))

        return list(reversed(res))


def main():
    T = int(input())
    for t in range(T):
        N = int(input())

        tree = list(map(int, input().split()))
        q = Queue()

        i = 0
        root = TreeNode(int(tree[i])) if tree else None
        q.put(root)
        i += 1

        while not q.empty():
            cur = q.get()

            if cur:
                if i < N and tree[i] != 'N':
                    left = TreeNode(int(tree[i]))
                    cur.left = left
                    q.put(cur.left)
                i += 1
                if i < N and tree[i] != 'N':
                    right = TreeNode(int(tree[i]))
                    cur.right = right
                    q.put(cur.right)
                i += 1

        res = Solution().levelOrderBottom(root)

        for level in res:
            for x in level:
                print(f"{x} ", endl="")
            print("")
           
        

if __name__ == "__main__":
    main()
