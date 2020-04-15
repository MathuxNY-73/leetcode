#!/usr/bin/env python3.6

from typing import List

import sys
import collections
import itertools
import random
import heapq

class Solution:
  def minMeetingRooms(self, intervals: List[List[int]]) -> int:
      if len(intervals) == 0:
            return 0

      s_to_e = {}
      for i in intervals:
          if not i[0] in s_to_e.keys():
              s_to_e[i[0]] = []
          s_to_e[i[0]].append(i[1])

      s_to_e = collections.OrderedDict(sorted(s_to_e.items()))
      pool = []

      res = 1
      for k, v in s_to_e.items():
          while len(pool) > 0 and k >= min(pool):
              heapq.heappop(pool)

          for e in v:
              heapq.heappush(pool, e)

          res = max(res, len(pool))

      return res

def main():
    lines = []
    for line in sys.stdin:
        lines.append(line.rstrip('\n'))

    T = int(lines.pop(0))

    for t in range(0,T):
        n = int(lines.pop(0))
        meetings = [[int(x) for x in lines.pop(0).split()] for _ in range(n)]
        print(meetings)
        res = Solution().minMeetingRooms(meetings)
        print(res)

if __name__ == "__main__":
    print("Hello World!")
    main()
