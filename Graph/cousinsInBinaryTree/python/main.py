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

    def __init__(self):
        self.m = {}

    def dfs(self, root: TreeNode, x: int, y: int, p: int, d: int) -> None:
        if root is None:
            return

        if root.val in {x, y}:
            self.m[root.val] = (p, d)
        self.dfs(root.left, x, y, root.val, d + 1)
        self.dfs(root.right, x, y, root.val, d + 1)

    
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        self.dfs(root, x, y, None, 0)
        x_t, y_t = self.m[x], self.m[y]
        return x_t[0] != y_t[0] and x_t[1] == y_t[1]

def main():
    T = int(input())
    for t in range(T):
        N = int(input())
        x, y = tuple(map(int, input().split()))

        tree = list(input().split())
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

        res = Solution().isCousins(root, x, y)

        print(res)


if __name__ == "__main__":
    main()
