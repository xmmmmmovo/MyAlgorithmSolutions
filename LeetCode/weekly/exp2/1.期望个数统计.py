from typing import List
from collections import Counter
from math import factorial


class Solution:
    def c(self, n, m):
        return factorial(n) // (factorial(m) * factorial(n - m))

    def expectNumber(self, scores: List[int]) -> int:
        if not scores:
            return 0

        c = Counter(scores)
        res = 0
        u, d = 1, 1
        for v in c.values():
            if v == 1:
                res += 1
            else:
                t = factorial(v)
                u *= (t * v + sum(self.c(v, i) * i for i in range(1, v-2)))
                d *= (t * t)

        return res if u == 1 and d == 1 else res + u//d


if __name__ == "__main__":
    assert Solution().expectNumber([1, 2, 3]) == 3
    assert Solution().expectNumber([1, 1]) == 1
    assert Solution().expectNumber([1, 1, 2]) == 2
    print(Solution().expectNumber([4, 3, 11, 2, 2, 9, 11, 15]))
