"""
输入整数数组 arr ，找出其中最小的 k 个数。
例如，输入4、5、1、6、2、7、3、8这8个数字，
则最小的4个数字是1、2、3、4。
限制：
0 <= k <= arr.length <= 10000
0 <= arr[i] <= 10000
"""
from typing import List


class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        arr.sort()
        return arr[:k]


if __name__ == "__main__":
    assert Solution().getLeastNumbers(arr=[3, 2, 1], k=2) == [1, 2]
    assert Solution().getLeastNumbers(arr=[0, 1, 2, 1], k=1) == [0]
