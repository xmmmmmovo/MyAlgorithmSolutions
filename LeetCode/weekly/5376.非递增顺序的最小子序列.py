from typing import List


class Solution:
    def minSubsequence(self, nums: List[int]) -> List[int]:
        if len(nums) < 2:
            return nums
        nums.sort(reverse=True)
        # print(nums)
        for i in range(1, len(nums)):
            # print(f'a{nums[:i]} b{nums[i:]}')
            if sum(nums[:i]) > sum(nums[i:]):
                return nums[:i]
        return nums


if __name__ == "__main__":
    assert Solution().minSubsequence([4, 3, 10, 9, 8]) == [10, 9]
    assert Solution().minSubsequence([4, 4, 7, 6, 7]) == [7, 7, 6]
    assert Solution().minSubsequence([6]) == [6]
