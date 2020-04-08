#
# @lc app=leetcode.cn id=322 lang=python3
#
# [322] 零钱兑换
#

from typing import List

# @lc code=start


class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        """
        dp
        """
        dp = [amount + 1] * (amount + 1)
        dp[0] = 0  # 0元的时候只能是0个
        for c in coins:
            for d in range(c, amount + 1):
                dp[d] = min(dp[d], dp[d - c] + 1)
        return dp[amount] if dp[amount] != amount + 1 else -1


class Solution2:
    def __init__(self):
        self.res = 0

    def dfs(self, coins, amount, idx, c):
        # print(f'coins={coins} amount={amount} idx={idx} c={c}')
        if amount == 0:
            # 如果剩下0就说明这是个可行解
            # 比对之后把小的值放进变量
            self.res = min(self.res, c)
            return

        if idx == len(coins):
            return

        k = amount // coins[idx]
        while k >= 0 and k + c < self.res:
            self.dfs(coins, amount - k * coins[idx], idx+1, c+k)
            k -= 1

    def coinChange(self, coins: List[int], amount: int) -> int:
        """
        贪心+dfs
        思路就是从大到小找
        """
        if amount == 0:
            return 0
        coins.sort(reverse=True)
        self.res = amount + 1
        self.dfs(coins, amount, 0, 0)
        return -1 if self.res == amount + 1 else self.res

# @lc code=end


if __name__ == "__main__":
    assert Solution2().coinChange(coins=[1, 2, 5], amount=11) == 3
    assert Solution2().coinChange(coins=[2], amount=3) == -1
    assert Solution2().coinChange(coins=[1], amount=2) == 2
