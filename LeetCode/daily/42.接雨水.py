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
        s1, s2 = 0, 0
        ml, mr = 0, 0
        s = 0
        for h in height:
            if h > ml:
                ml = h
            s1 += ml
            s += h

        for h in reversed(height):
            if h > mr:
                mr = h
            s1 += mr

        return s1 + s2 - ml * len(height) - s


class Solution3:
    def trap(self, height: List[int]) -> int:
        """
        双指针
        左右向中心遍历
        为什么可以双指针
        指定了左右最大值之后 中间的无论如何都不可能超出这个值
        这个就相当于一个左右指针碗 中间的某一格必定能盛到左右最大值那里
        """
        l, r = 0, len(height) - 1
        res = 0
        ml, mr = 0, 0

        while l < r:
            # print(f'l={l}r={r}')
            # 这里的意思是判断是左边
            if height[l] < height[r]:
                if height[l] >= ml:
                    ml = height[l]
                else:
                    res += ml - height[l]

                l += 1
            else:
                if height[r] >= mr:
                    mr = height[r]
                else:
                    res += mr - height[r]

                r -= 1
        return res
# @lc code=end


if __name__ == "__main__":
    assert Solution3().trap([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]) == 6
