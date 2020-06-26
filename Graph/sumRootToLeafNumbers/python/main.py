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
        self.res = 0

    def runThruTree(self, root: TreeNode, value: int) -> None:
        if root.right is None and root.left is None:
            self.res += (value * 10 + root.val)
        else:
            if root.left:
                self.runThruTree(root.left, value * 10 + root.val)
            if root.right:
                self.runThruTree(root.right, value * 10 + root.val)

    def sumNumbers(self, root: TreeNode) -> int:
        if root is None:
            return 0
        else:
            self.runThruTree(root, 0)
            return self.res


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
                if i < N and tree[i] != 'null':
                    left = TreeNode(int(tree[i]))
                    cur.left = left
                    q.put(cur.left)
                i += 1
                if i < N and tree[i] != 'null':
                    right = TreeNode(int(tree[i]))
                    cur.right = right
                    q.put(cur.right)
                i += 1

        res = Solution().possibleBipartition(N, dislikes)

        print(res)


if __name__ == "__main__":
    main()
