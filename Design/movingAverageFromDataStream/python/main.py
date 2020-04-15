#!/usr/bin/env python3

from typing import List
import sys
import collections
import itertools
from queue import Queue

class MovingAverage:

    def __init__(self, size: int):
        """
        Initialize your data structure here.
        """
        self._size = size
        self._cnt = 0
        self._sum = 0
        self._q = Queue(size)

    def next(self, val: int) -> float:
        self._sum += val
        self._cnt += 1

        if self._cnt > self._size:
            self._sum -= self._q.get()
            self._cnt -= 1

        self._q.put(val)
        return self._sum / float(self._cnt)


lines = []
for line in sys.stdin:
    lines.append(line.rstrip('\n'))

T = int(lines.pop(0))

for t in range(0,T):
    W, _ = tuple(map(int, lines.pop(0).split(' ')))

    ma = MovingAverage(W)

    for n in [int(x) for x in lines.pop(0).split()]:
        print(ma.next(n))

if __name__ == "__main__":
    print("Hello World!")
