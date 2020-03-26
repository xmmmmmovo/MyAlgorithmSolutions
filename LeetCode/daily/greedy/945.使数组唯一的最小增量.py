#
# @lc app=leetcode.cn id=945 lang=python3
#
# [945] 使数组唯一的最小增量
#

from typing import List

# @lc code=start

from collections import Counter


class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        if len(A) < 2:
            return 0

        ans = 0
        A.sort()
        for k in range(1, len(A)):
            if A[k] <= A[k-1]:
                t = A[k-1] - A[k] + 1
                A[k] += t
                ans += t
        return ans


class Solution2:
    def minIncrementForUnique(self, A: List[int]) -> int:
        if len(A) < 2:
            return 0

        c = [0 for i in range(40000)]
        m = -1

        for a in A:
            c[a] += 1
            m = max(m, a)

        move = 0
        for i in range(m+1):
            if c[i] > 1:
                d = c[i] - 1
                move += d
                c[i+1] += d

        d = c[m+1]-1
        move += (1+d) * d//2
        return move

# @lc code=end


if __name__ == "__main__":
    assert Solution2().minIncrementForUnique([1, 2, 2]) == 1
    assert Solution2().minIncrementForUnique([3, 2, 1, 2, 1, 7]) == 6
