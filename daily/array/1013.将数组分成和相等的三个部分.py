#
# @lc app=leetcode.cn id=1013 lang=python3
#
# [1013] 将数组分成和相等的三个部分
#

# @lc code=start
from typing import List


class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        suma = sum(A)
        if suma % 3 != 0:
            return False

        cnt, sum_it = 0, 0
        suma //= 3

        for a in A:
            sum_it += a
            if sum_it == suma:
                cnt += 1
                sum_it = 0

        # 这里必须判断是>3因为有可能有重复区间==suma//3的情况
        # 例如[10, -10,// 10, -10,// 10, -10, 10, -10]
        return sum_it == 0 and cnt >= 3


class Solution2:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        """
        这种解法就不需要判断了
        效率还比上面的解法高
        """
        suma = sum(A)
        if suma % 3 != 0:
            return False

        cnt, sum_it = 0, 0
        suma //= 3

        for a in A:
            sum_it += a
            if sum_it == suma:
                cnt += 1
                sum_it = 0
                if cnt == 3:
                    return True
        return False


# @lc code=end
if __name__ == "__main__":
    print(Solution().canThreePartsEqualSum(
        [0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1]))
    print(Solution().canThreePartsEqualSum(
        [0, 2, 1, -6, 6, 7, 9, -1, 2, 0, 1]))
    print(Solution().canThreePartsEqualSum([3, 3, 6, 5, -2, 2, 5, 1, -9, 4]))
    print(Solution().canThreePartsEqualSum(
        [10, -10, 10, -10, 10, -10, 10, -10]))
