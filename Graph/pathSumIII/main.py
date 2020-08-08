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
        self.m = dict({0: 1})
        self.cnt = 0

    def dfs(self, root: TreeNode, prefix_sum: int, target: int) -> None:
        if root is None:
            return

        prefix_sum += root.val
        self.cnt += self.m.get(prefix_sum - target, 0)

        if prefix_sum not in self.m:
            self.m[prefix_sum] = 0
        self.m[prefix_sum] += 1

        self.dfs(root.left, prefix_sum, target)
        self.dfs(root.right, prefix_sum, target)

        self.m[prefix_sum] -= 1


    def pathSum(self, root: TreeNode, sum: int) -> int:
        self.dfs(root, 0, sum)
        return self.cnt


def main():
    T = int(input())
    for t in range(T):
        N, target = tuple(map(int, input().split()))

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

        res = Solution().pathSum(root, target)

        print(res)

        

if __name__ == "__main__":
    main()
