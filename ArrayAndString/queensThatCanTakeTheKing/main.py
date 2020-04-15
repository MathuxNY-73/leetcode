#!/usr/bin/env python3.6

from typing import List, Callable, Tuple

import sys
import collections
import itertools
import random
from queue import Queue

class Solution:

    dx = [-1, 0, 1,-1, 0, 1,-1, 1]
    dy = [-1,-1,-1, 1, 1, 1, 0, 0]

    @staticmethod
    def build_move(dx: int, dy: int) -> Callable[[int,int], Tuple[int, int]]:
        def move(x: int, y: int) -> Tuple[int, int]:
            return x + dx, y + dy
        return move


    def queensAttacktheKing(self, queens: List[List[int]], king: List[int]) -> List[List[int]]:
      q = Queue()
      q.put((tuple(king), [Solution.build_move(self.dx[i], self.dy[i]) for i in range(8)]))
      res = []
      queens_s = set(map(tuple, queens))

      while not q.empty():
          (x, y), mov = q.get()
          print("Visiting square: ({},{})".format(x, y), file=sys.stderr)
          for m in mov:
              xx, yy = m(x, y)
              print("From square ({},{}) checking visit on square: ({},{})".format(x, y, xx, yy), file=sys.stderr)
              if min(xx, yy) < 0 or xx >= 8 or yy >= 8:
                  continue
              if (xx,yy) in queens_s:
                  res.append([xx,yy])
              else:
                  print("From square ({},{}) will visit square: ({},{})".format(x, y, xx, yy), file=sys.stderr)
                  q.put(((xx,yy), [m]))
      return res


def main():
    lines = []
    for line in sys.stdin:
        lines.append(line.rstrip('\n'))

    T = int(lines.pop(0))

    for t in range(0,T):
        q = int(lines.pop(0))
        king = [int(x) for x in lines.pop(0).split()]
        queens = [[int(x) for x in lines.pop(0).split()] for _ in range(q)]
        res = Solution().queensAttacktheKing(queens, king)
        print(res)

if __name__ == "__main__":
    print("Hello World!")
    main()
