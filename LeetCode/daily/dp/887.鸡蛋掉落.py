#
# @lc app=leetcode.cn id=887 lang=python3
#
# [887] 鸡蛋掉落
#

# @lc code=start


class Solution:
    def superEggDrop(self, K: int, N: int) -> int:
        """
        暴力dp 超时
        o k*n*n
        """
        d = dict()

        def dp(k, n):
            if k == 1:
                return n
            if n == 0:
                return 0

            if (k, n) in d:
                return d[(k, n)]

            res = float('INF')
            for i in range(1, n+1):
                res = min(
                    res,
                    max(
                        dp(k, n - i),
                        dp(k - 1, i - 1)
                    ) + 1
                )

            d[(k, n)] = res
            return res
        return dp(K, N)


class Solution2:
    def superEggDrop(self, K: int, N: int) -> int:
        """
        二分优化dp 超时
        o k * n * logn
        """
        d = dict()

        def dp(k, n):
            if k == 1:
                return n
            if n == 0:
                return 0

            if (k, n) in d:
                return d[(k, n)]

            res = float('INF')

            # 二分搜索
            l, h = 1, n
            while l <= h:
                m = (l + h) // 2
                b = dp(k - 1, m - 1)
                nb = dp(k, n - m)

                if b > nb:
                    h = m - 1
                    res = min(res, b + 1)
                else:
                    l = m + 1
                    res = min(res, nb + 1)

            d[(k, n)] = res
            return res
        return dp(K, N)


class Solution3:
    def superEggDrop(self, K: int, N: int) -> int:
        """
        状态转移优化dp
        o k * n
        """
        dp = [[0] * (N + 1) for _ in range(K + 1)]

        m = 0
        while dp[K][m] < N:
            m += 1
            for i in range(1, K+1):
                dp[i][m] = dp[i][m - 1] + dp[i - 1][m - 1] + 1
        return m

# @lc code=end


if __name__ == "__main__":
    assert Solution3().superEggDrop(K=1, N=2) == 2
    assert Solution3().superEggDrop(K=2, N=6) == 3
    assert Solution3().superEggDrop(K=3, N=14) == 4
