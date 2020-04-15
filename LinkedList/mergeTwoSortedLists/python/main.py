#!/usr/bin/env python3.6

from typing import List, Optional, Tuple

import sys
import collections
import itertools
import random
from queue import PriorityQueue
import numpy as np

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy = ListNode(0)
        cur = dummy
        while l1 and l2:
            if l1.val > l2.val:
                cur.next = l2
                l2 = l2.next
            else:
                cur.next = l1
                l1 = l1.next
            cur = cur.next
        cur.next = l1 if l1 is not None else l2
        return dummy.next

def main():
    lines = []
    for line in sys.stdin:
        lines.append(line.rstrip('\n'))

    T = int(lines.pop(0))

    for t in range(0,T):
        _ = int(lines.pop(0))
        dummy = ListNode(0)
        cur = dummy
        for x in lines.pop(0).split():
            cur.next = ListNode(int(x))
            cur = cur.next
        l1 = dummy.next
        _ = int(lines.pop(0))
        cur = dummy
        for x in lines.pop(0).split():
            cur.next = ListNode(int(x))
            cur = cur.next
        l2 = dummy.next

        res = Solution().mergeTwoLists(l1,l2)
        while res:
            print(res.val)
            res = res.next


if __name__ == "__main__":
    print("Hello World!")
    main()
