#
# @lc app=leetcode.cn id=169 lang=python3
#
# [169] 多数元素
#
from typing import List

# @lc code=start


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        ans = {}

        for num in nums:
            if ans.get(num) is None:
                ans[num] = 1
            else:
                ans[num] += 1

        for (k, v) in ans.items():
            if v > len(nums)/2:
                return k

# @lc code=end


if __name__ == "__main__":
    print(Solution().majorityElement([3, 2, 3]))
    print(Solution().majorityElement([2, 2, 1, 1, 1, 2, 2]))
    