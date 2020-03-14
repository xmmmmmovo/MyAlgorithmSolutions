#
# @lc app=leetcode.cn id=169 lang=python3
#
# [169] 多数元素
#
from typing import List

# @lc code=start

from collections import Counter


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


class Solution2:
    def majorityElement(self, nums: List[int]) -> int:
        counts = Counter(nums)
        return max(counts.keys(), key=counts.get)


class Solution3:
    """
    随机算法
    平均o(n)/o(1)
    """

    def majorityElement(self, nums: List[int]) -> int:
        majority_count = len(nums)//2
        while True:
            candidate = random.choice(nums)
            # 求次数/众数
            if sum(1 for elem in nums if elem == candidate) > majority_count:
                return candidate


class Solution3:
    """
    Boyer-Moore 投票算法
    o(n)/o(1)
    """

    def majorityElement(self, nums: List[int]) -> int:
        count = 0
        candidate = None

        for num in nums:
            if count == 0:
                candidate = num
            
            count += (1 if candidate == num else -1)
        
        return candidate

# @lc code=end


if __name__ == "__main__":
    print(Solution().majorityElement([3, 2, 3]))
    print(Solution().majorityElement([2, 2, 1, 1, 1, 2, 2]))
