from typing import List
from queue import Queue


class Solution:
    def minJump(self, jump: List[int]) -> int:
        vis = [[False for _ in range(len(jump))] for _ in range(len(jump))]
        res = 0

        def dfs(p, f, n):
            if p >= len(jump):
                res = n if n < res else res

            if vis[f][p]:
                return

            dfs(p + jump[p], p, n + 1)
            for i in jump[:p]:
                dfs(i, p, n + 1)

        res = dfs(0, 0, 0)


if __name__ == "__main__":
    assert Solution().minJump([2, 5, 1, 1, 1, 1]) == 3
