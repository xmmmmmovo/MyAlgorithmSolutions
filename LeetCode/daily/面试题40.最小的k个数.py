"""
输入整数数组 arr ，找出其中最小的 k 个数。
例如，输入4、5、1、6、2、7、3、8这8个数字，
则最小的4个数字是1、2、3、4。
限制：
0 <= k <= arr.length <= 10000
0 <= arr[i] <= 10000
"""
from typing import List
from random import randint


class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        """
        最简单的直接sort就完事儿了
        o(nlogn)
        """
        arr.sort()
        return arr[:k]


class Solution2:
    """
    这里的思想跟快排一样
    就是选取标定点 使得左边的都比标定点小 右边的都比标定点大
    """

    def partition(self, nums, l, r):
        pivot = nums[r]
        i = l - 1
        for j in range(l, r):
            if nums[j] <= pivot:
                i += 1
                nums[i], nums[j] = nums[j], nums[i]
        nums[i + 1], nums[r] = nums[r], nums[i + 1]
        return i + 1

    def randomized_partition(self, nums, l, r):
        i = randint(l, r)
        nums[r], nums[i] = nums[i], nums[r]
        return self.partition(nums, l, r)

    def randomized_selected(self, arr, l, r, k):
        pos = self.randomized_partition(arr, l, r)
        num = pos - l + 1
        if k < num:
            self.randomized_selected(arr, l, pos - 1, k)
        elif k > num:
            self.randomized_selected(arr, pos + 1, r, k - num)

    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        if k == 0:
            return list()
        # 随机选择
        self.randomized_selected(arr, 0, len(arr) - 1, k)
        return arr[:k]


if __name__ == "__main__":
    assert Solution2().getLeastNumbers(arr=[3, 2, 1], k=2) == [1, 2]
    assert Solution2().getLeastNumbers(arr=[0, 1, 2, 1], k=1) == [0]
