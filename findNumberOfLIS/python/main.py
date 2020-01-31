#!/usr/bin/env python3.6

from typing import List

import sys
import collections
import itertools
import random

class TreeNode:
    def __init__(self, start: int, end: int) -> None:
        self.start = start
        self.end = end
        self.left = None
        self.right = None
        self.val = (0,1)

    def get_left(self) -> 'TreeNode':
        if not self.left:
            self.left = TreeNode(self.start, (self.start + self.end) // 2)
        return self.left

    def get_right(self) -> 'TreeNode':
        if not self.right:
            self.right =  TreeNode((self.start + self.end) // 2 + 1, self.end)
        return self.right

class SegTree:

    def build(nums: List[int]) -> TreeNode:
        root = TreeNode(min(nums), max(nums))
        for el in nums:
            (l, cnt) = SegTree.get(root, el - 1)
            SegTree.add(root, (l + 1, cnt), el)

        return root

    def get(v: TreeNode, k: int) -> (int, int):
        if k >= v.end:
            return v.val
        elif k < v.start:
            return (0, 1)
        else:
            return SegTree.combine(SegTree.get(v.get_left(), k), SegTree.get(v.get_right(), k))

    def add(v: TreeNode, val: (int, int), k: int, cnt: int = 10) -> None:
        #print("start: {}, end: {}, k: {}".format(v.start, v.end, k))
        #if cnt == 0:
        #    print("Max recursion reached!")
        #    return
        if v.start == v.end:
            print("Set val={} for [{},{}] with k={}".format(val, v.start, v.end, k))
            v.val = SegTree.combine(val, v.val)
        else:
            m = (v.start + v.end) // 2
            if k <= m:
                SegTree.add(v.get_left(), val, k, cnt -1)
            else:
                SegTree.add(v.get_right(), val, k, cnt -1)
            print("For interval [{},{}], val was {} for k= {}".format(v.start, v.end, v.val, k))
            v.val = SegTree.combine(v.get_left().val, v.get_right().val)
            print("For interval [{},{}], val is {} for k= {}".format(v.start, v.end, v.val, k))

    def combine(l: (int, int), r: (int, int)) -> (int, int):
        if l[0] > r[0]:
            return l
        elif l[0] < r[0]:
            return r
        else:
            return (l[0], l[1]+r[1]) if l[0] else (0, 1)

class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        dp = []
        numb = []

        for i, n in enumerate(nums):
            dp.append(0)
            numb.append(1)
            for j in reversed(range(0,i)):
                if nums[j] < n:
                    if dp[j] > dp[i]:
                        dp[i] = dp[j]
                        numb[i] = numb[j]
                    elif dp[j] == dp[i]:
                        numb[i] += numb[j]
            dp[i] += 1

        print(dp)
        print(numb)
        m = max(dp)
        return sum([numb[i] for i, n in enumerate(dp) if n == m])

    def findNumberOfLISTree(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0

        seg_tree = SegTree.build(nums)
        return seg_tree.val[1]


def main():
    lines = []
    for line in sys.stdin:
        lines.append(line.rstrip('\n'))

    T = int(lines.pop(0))

    for t in range(0,T):
        _ = int(lines.pop(0))
        nums = [int(x) for x in lines.pop(0).split()]
        res = Solution().findNumberOfLISTree(nums)
        print(res)

if __name__ == "__main__":
    print("Hello World!")
    main()
