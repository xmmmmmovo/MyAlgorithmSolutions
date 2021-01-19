
from collections import deque


def d_sum(num):
    res = 0
    while num:
        res += num % 10
        num //= 10
    return res


class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        """
        bfs解法
        """
        d = deque()
        s = set()
        d.append((0, 0))
        dirs = [(1, 0), (0, 1)]

        while len(d) != 0:
            p = d.popleft()
            if p in s:
                continue
            s.add(p)
            for dd in dirs:
                dx = p[0] + dd[0]
                dy = p[1] + dd[1]
                if dx != -1 and dx != m and dy != -1 and dy != n and d_sum(dx) + d_sum(dy) <= k:
                    d.append((dx, dy))

        return len(s)


if __name__ == "__main__":
    assert Solution().movingCount(m=2, n=3, k=1) == 3
    assert Solution().movingCount(m=3, n=1, k=0) == 1
