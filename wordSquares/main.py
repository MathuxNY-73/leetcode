#!/usr/bin/env python3.6

from typing import List, Optional, Tuple

import sys
import collections
import itertools
import random
from queue import Queue

class TrieNode:
    def __init__(self):
        self._alphabet: List[Optional['TrieNode']] = [None for _ in range(26)]
        self.leaf = True

    def get_all(self) -> List[Tuple[chr, 'TrieNode']]:
        return [(chr(ord('a')+i), n) for i,n in enumerate(self._alphabet) if n]
   
    def get(self, c: chr) -> Optional['TrieNode']:
        return self._alphabet[ord(c) - ord('a')]

    def set(self, c: chr) -> 'TrieNode':
        idx = ord(c) - ord('a')
        if self._alphabet[idx] is None:
            self._alphabet[idx] = TrieNode()
        self.leaf = False
        return self._alphabet[idx]

class Trie:
    def __init__(self, words: List[str]):
        self._root = TrieNode()
        self.build(words)

    def build(self, words: List[str]):
        for w in words:
            cur = self._root
            for c in w:
                cur = cur.set(c)

    def get(self, prefix: str) -> List[str]:
        cur = self._root
        for c in prefix:
            if cur:
                cur = cur.get(c)

        if not cur:
            return []

        res = []
        self.bfs(cur, prefix, res)
        return res

    def bfs(self, root: TrieNode, prefix: str, res: List[str]):
        q = Queue()
        q.put((prefix, root))

        while not q.empty():
            cur_w, cur = q.get()
            if cur.leaf:
                res.append(cur_w)
                continue

            for c, n in cur.get_all():
                q.put((cur_w + c, n))

    def dfs(self, cur: TrieNode, cur_w: str, res: List[str]):
        if cur.leaf:
            res.append(cur_w)
            return
        for c, n in cur.get_all():
            self.dfs(n, cur_w + c, res)



class Solution:

    def backtrack(self, wordSquare: List[str], res: List[List[str]], index: int, trie: Trie):
        if index >= len(wordSquare[0]):
            res.append(wordSquare)
            return

        prefix = ''.join([w[index] for w in wordSquare])
        candidates = trie.get(prefix)

        for w in candidates:
            self.backtrack(wordSquare + [w], res, index + 1, trie)

    def getWordsStartingWithPrefix(self, prefix: str, words: List[str]) -> List[str]:
        return [w for w in words if w.startswith(prefix)]

    def wordSquares(self, words: List[str]) -> List[List[str]]:
        res = []
        trie = Trie(words)
        for w in words:
            self.backtrack([w], res, 1, trie)
        return res


def main():
    lines = []
    for line in sys.stdin:
        lines.append(line.rstrip('\n'))

    T = int(lines.pop(0))

    for t in range(0,T):
        _ = int(lines.pop(0))
        nums = [str(x) for x in lines.pop(0).split()]
        #print(nums)
        res = Solution().wordSquares(nums)
        print(res)

if __name__ == "__main__":
    print("Hello World!")
    main()
