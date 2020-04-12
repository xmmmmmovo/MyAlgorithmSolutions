from typing import List


class Solution:
    def processQueries(self, queries: List[int], m: int) -> List[int]:
        res = []
        p = list(range(1, m+1))
        for i in queries:
            tmp = p.index(i)
            res.append(tmp)
            p = [p[tmp]] + p[:tmp] + p[tmp+1:]
        return res


if __name__ == "__main__":
    assert Solution().processQueries(queries=[3, 1, 2, 1], m=5) == [2, 1, 2, 1]
    assert Solution().processQueries(queries=[4, 1, 2, 2], m=4) == [3, 1, 2, 0]
    assert Solution().processQueries(
        queries=[7, 5, 5, 8, 3], m=8) == [6, 5, 0, 7, 5]
