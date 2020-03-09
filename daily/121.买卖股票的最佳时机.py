#
# @lc app=leetcode.cn id=121 lang=python3
#
# [121] 买卖股票的最佳时机
#

# @lc code=start

from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        from pprint import pprint
        from sys import maxsize

        # 最开始结果是0
        res = 0
        # 起初最小值就是最大值
        min_price = maxsize

        for price in prices:
            pass

        pass

# @lc code=end


if __name__ == "__main__":
    Solution().maxProfit([7, 1, 5, 3, 6, 4])
    Solution().maxProfit([7, 6, 4, 3, 1])
