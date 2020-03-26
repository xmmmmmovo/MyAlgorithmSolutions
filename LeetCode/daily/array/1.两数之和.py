#
# @lc app=leetcode.cn id=1 lang=python3
#
# [1] 两数之和
#

# @lc code=start
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dct = {}
        for i, n in enumerate(nums):
            if target - n in dct:
                return [dct[target - n], i]
            dct[n] = i

# @lc code=end

