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

    def helper(self, root: TreeNode, l: int, r: int, t: int) -> bool:
        if not root:
            return False
        if l == r:
            return True

        m = l + (r - l) // 2
        if t > m:
            return self.helper(root.right, m + 1, r, t)
        else:
            return self.helper(root.left, l, m, t)

    def countNodes(self, root: TreeNode) -> int:
        if not root:
            return 0

        cur = root
        depth = 0
        while cur:
            cur = cur.left
            depth += 1
        depth -= 1

        start = 0
        end = 1 << depth
        l = 1
        r = end - 1
        while l <= r:
            m = l + (r - l) // 2
            if self.helper(root, start, end - 1, m):
                l = m + 1
            else:
                r = m - 1

        return (1 << depth) + l - 1

        

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

        res = Solution().countNodes(root)

        print(res)


if __name__ == "__main__":
    main()
