#
# @lc app=leetcode.cn id=121 lang=python3
#
# [121] 买卖股票的最佳时机
#

# @lc code=start

from typing import List
from sys import maxsize

class Solution:
    def maxProfit(self, prices: List[int]) -> int:

        # 最开始结果是0
        res = 0
        # 起初最小值就是最大值
        min_price = maxsize

        for price in prices:
            min_price = min(min_price, price)
            res = max(res, price - min_price)

        return res

# @lc code=end


if __name__ == "__main__":
    print(Solution().maxProfit([7, 1, 5, 3, 6, 4]))
    print(Solution().maxProfit([7, 6, 4, 3, 1]))
