#
# @lc app=leetcode.cn id=912 lang=python3
#
# [912] 排序数组
#
from typing import List
# @lc code=start

from random import randint


class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        nums.sort()
        return nums


class Solution2:
    def sortArray(self, nums: List[int]) -> List[int]:
        """
        非比较排序
        """
        max_n = max(nums)
        min_n = min(nums)

        c = [0 for _ in range(max_n - min_n + 1)]

        for n in nums:
            c[n - min_n] += 1

        idx = 0
        for k, v in enumerate(c):
            while v:
                nums[idx] = k + min_n
                idx += 1
                v -= 1

        return nums


class Solution3:
    def random_partition(self, nums, l, r):
        """
        选取随机标定点
        """
        p = randint(l, r)  # 从中选标定点
        nums[p], nums[r] = nums[r], nums[p]  # 先交换到尾部 不然会成为o(n2)
        i = l - 1
        # 判断区间内部左右交换元素
        for j in range(l, r):
            if nums[j] < nums[r]:
                i += 1
                nums[j], nums[i] = nums[i], nums[j]
        i += 1
        nums[i], nums[r] = nums[r], nums[i]  # 再交换回来
        return i

    def random_qsort(self, nums, l, r):
        """
        快排主函数
        然后递归调用左右
        """
        if r - l <= 0:
            return
        mid = self.random_partition(nums, l, r)
        self.random_qsort(nums, l, mid - 1)
        self.random_qsort(nums, mid + 1, r)

    def sortArray(self, nums: List[int]) -> List[int]:
        self.random_qsort(nums, 0, len(nums) - 1)
        return nums


class Solution4:
    def sortArray(self, nums: List[int]) -> List[int]:
        """
        桶排序
        TODO:并行桶排序
        """
        if len(nums) <= 1:
            return nums

        max_n = max(nums)
        min_n = min(nums)

        # 桶的大小
        bucket_range = (max_n-min_n) / len(nums)
        # 桶数组
        count_list = [[] for i in range(len(nums) + 1)]
        # 向桶数组填数
        for i in nums:
            # 看在那个分区内部然后填数据
            count_list[int((i-min_n)//bucket_range)].append(i)
        nums.clear()
        # 回填，这里桶内部排序直接调用了sorted
        for i in count_list:
            # 对桶内数据排序
            for j in sorted(i):
                nums.append(j)

        return nums

# @lc code=end


print(Solution3().sortArray([5, 2, 3, 1]))
