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
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        sum = 0

        cur = root
        while cur:
            if cur.left is None:
                cur = cur.right
            else:
                prev = cur.left
                if prev.left is None and prev.right is None:
                    sum += prev.val
                while prev.right and prev.right != cur:
                    cur = cur.right

                if prev.right is None:
                    prev.right = cur
                    cur = cur.left
                else:
                    prev.right = None
                    cur = cur.right
        return sum


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

        res = Solution().sumOfLeftLeaves(root)

        print(res)


if __name__ == "__main__":
    main()
