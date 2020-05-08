from typing import List
from collections import defaultdict


class Solution:
    def __init__(self):
        self.res = 0

    def numWays(self, n: int, relation: List[List[int]], k: int) -> int:
        """
        dfs 超时用dp
        """

        def dfs(relation, cnt, p):
            # print(f'res={self.res}, cnt={cnt}')

            if p == n-1 and cnt == k:
                self.res += 1
                return
            if cnt > k:
                return

            for i in relation[p]:
                dfs(relation, cnt + 1, i)

        d = defaultdict(list)

        for i in relation:
            d[i[0]].append(i[1])

        dfs(d, 0, 0)

        return self.res


if __name__ == "__main__":
    assert Solution().numWays(n=5, relation=[[0, 2], [2, 1], [3, 4], [
        2, 3], [1, 4], [2, 0], [0, 4]], k=3) == 3
    assert Solution().numWays(n=3, relation=[[0, 2], [2, 1]], k=2) == 0
