#!/usr/bin/env python3

from typing import List
import sys
import collections
import itertools
import math
import heapq

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        n, m = len(nums1), len(nums2)
        A, B = nums1, nums2

        if m <= n:
            n, m = m, n
            A, B = B, A

        if n == 0:
            if m & 1:
                return B[m // 2]
            else:
                return (B[m // 2 - 1] + B[m // 2]) / 2.0

        imin, imax = 0, n

        while imin <= imax:
            i = imin + (imax - imin) // 2
            j = (m + n + 1) // 2 - i

            if i < imax and A[i] < B[j - 1]:
                imin = i + 1
            elif i > imin and B[j] < A[i - 1]:
                imax = i - 1
            else:

                max_left = 0
                if i == 0:
                    max_left = B[j - 1]
                elif j == 0:
                    max_left = A[i - 1]
                else:
                    max_left = A[i - 1] if A[i - 1] > B[j - 1] else B[j - 1]

                min_right = 0
                if i == n:
                    min_right = B[j]
                elif j == m:
                    min_right = A[i]
                else:
                    min_right = A[i] if A[i] > B[j] else B[j]


                if m + n & 1:
                    return max_left
                else:
                    return (max_left + min_right) / 2.0

        return 0


def main():
    T = int(input())

    for t in range(0,T):
        N, M = tuple(map(int, input().split()))
        nums1 = list(map(int, input().split()))
        nums2 = list(map(int, input().split()))

        res = Solution().findMedianSortedArrays(nums1, nums2)
        print(res)

if __name__ == "__main__":
    main()
