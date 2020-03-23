"""
5178. 四因数
给你一个整数数组 nums，
请你返回该数组中恰有四个因数的这些整数的各因数之和。
如果数组中不存在满足题意的整数，则返回 0 。
示例：

输入：nums = [21,4,7]
输出：32
解释：
21 有 4 个因数：1, 3, 7, 21
4 有 3 个因数：1, 2, 4
7 有 2 个因数：1, 7
答案仅为 21 的所有因数的和。

提示：

1 <= nums.length <= 10^4
1 <= nums[i] <= 10^5
"""
from typing import List


class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        """
        线性筛法
        """
        if not nums:
            return 0

        top = max(nums)

        isP = [True for _ in range(top)]

        # 从2开始筛 只用判断前√top便可以筛掉所有的了
        i = 2
        while i * i < top:
            # 判断是不是已经被筛掉了
            if isP[i]:
                # 没有就从i²开始筛
                j = i * i
                while j < top:
                    isP[j] = False
                    # 这里其实相当于n * i
                    j += i

            i += 1

        p = [i for i in range(2, top) if isP[i]]

        ans = 0
        for num in nums:
            for pp in p:
                # 已经不可能了，后续不算了
                if pp * pp > num:
                    break
                # 立方数是符合的，这个比较坑，开始没想到，比如 8
                if pp * pp * pp == num:
                    ans += (1 + num + pp + pp * pp)
                    break
                # 可以分解成两个质数乘积
                if num % pp == 0 and isP[num // pp] and pp * pp != num:
                    ans += (1 + num + pp + num // pp)
                    break
        
        return ans


if __name__ == "__main__":
    assert Solution().sumFourDivisors([21, 4, 7]) == 32
