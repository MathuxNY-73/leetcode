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
    def closestValue(self, root: TreeNode, target: float) -> int:
        closest = 0
        min_dist = float("inf")

        cur = root
        while cur:
            if abs(float(cur.val) - target) < min_dist:
                closest = cur.val
                min_dist = abs(float(cur.val) - target)

            if cur.val >= target:
                cur = cur.left
            else:
                cur = cur.right

        return closest


def main():
    T = int(input())
    for t in range(T):
        N, target = tuple(map(float, input().split()))
        N = int(N)

        tree = list(map(str, input().split()))
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

        res = Solution().closestValue(root, target)

        print(res)

        

if __name__ == "__main__":
    main()
