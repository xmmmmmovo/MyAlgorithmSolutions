#
# @lc app=leetcode.cn id=300 lang=python3
#
# [300] 最长上升子序列
#

from typing import List

# @lc code=start


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        """
        dp解法
        o(n2)
        """
        # 这里一定记得判空
        if not nums:
            return 0

        dp = [1] * len(nums)

        for (i, v) in enumerate(nums):
            for j in range(i):
                if nums[j] < v:
                    # 这里因为会循环一遍判断最大值所以能判断dp[i]永远最大
                    dp[i] = max(dp[i], dp[j] + 1)

        return max(dp)


class Solution2:
    def lengthOfLIS(self, nums: List[int]) -> int:
        """
        贪心+二分解法
        这里应该叫二分插入而不是二分查找
        总体思路就是将每位元素二分插入tail中
        总的是让tail里存储比较小的元素，这样虽然不是真实序列
        但是长度是对的
        o(nlogn)
        """
        # 依旧是判空
        if len(nums) < 2:
            return len(nums)

        res = 0
        tail = [nums[0]]

        for num in nums:
            if num > tail[-1]:
                tail.append(num)
                continue

            l, r = 0, len(tail) - 1
            while l < r:
                mid = l + (r - l) // 2
                if tail[mid] < num:
                    l = mid + 1
                else:
                    r = mid

            # 找到插入点进行赋值/插入
            tail[l] = num
        return len(tail)


# @lc code=end
if __name__ == "__main__":
    print(Solution().lengthOfLIS([10, 9, 2, 5, 3, 7, 101, 18]))
