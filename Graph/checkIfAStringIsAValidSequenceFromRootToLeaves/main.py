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

    def isValidSequence(self, root: TreeNode, arr: List[int]) -> bool:
        if root is None:
            return len(arr) == 0

        if len(arr) == 0 or root.val != arr[0]:
            return False

        left = self.isValidSequence(root.left, arr[1:])
        right = self.isValidSequence(root.right, arr[1:])

        return left and right if len(arr) == 1 else left or right


def main():
    T = int(input())
    for t in range(T):
        N, A = tuple(map(int, input().split()))

        tree = list(input().split())
        arr = list(map(int, input().split()))
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

        res = Solution().isValidSequence(root, arr)

        print(res)


if __name__ == "__main__":
    main()
