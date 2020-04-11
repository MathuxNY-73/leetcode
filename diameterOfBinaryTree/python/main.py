#! /usr/bin/env python3.7

from typing import List, Optional, Tuple

import sys
import collections
import itertools
import random
from queue import Queue

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def __init__(self) -> 'Solution':
        self.m = - float("inf")

    def dfs(self, root: TreeNode) -> int:
        if root is None:
            return -1

        left = self.dfs(root.left) + 1
        right = self.dfs(root.right) + 1

        self.m = max(left + right, self.m);

        return max(left, right)

    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        if root is None:
            return 0

        left = self.dfs(root.left) + 1
        right = self.dfs(root.right) + 1

        return max(left + right ,self.m)


def main():
    T = int(input())
    for t in range(T):
        N = int(input())

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

        res = Solution().diameterOfBinaryTree(root)

        print(res)


if __name__ == "__main__":
    main()
