#
# @lc app=leetcode.cn id=42 lang=python3
#
# [42] 接雨水
#
from typing import List
# @lc code=start


class Solution:
    def trap(self, height: List[int]) -> int:
        """
        暴力解法
        """
        res = 0
        for i in range(1, len(height)-1):
            ml = max(height[:i+1])
            mr = max(height[i:])
            res += min(ml, mr) - height[i]
            # print(f'ml = {ml} mr = {mr} res = {res}')
        return res


class Solution2:
    def trap(self, height: List[int]) -> int:
        """
        动态编程
        韦恩图求交集解法
        """
        res = 0
        for i in range(1, len(height)-1):
            ml = max(height[:i+1])
            mr = max(height[i:])
            res += min(ml, mr) - height[i]
            # print(f'ml = {ml} mr = {mr} res = {res}')
        return res
# @lc code=end


if __name__ == "__main__":
    assert Solution().trap([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]) == 6
