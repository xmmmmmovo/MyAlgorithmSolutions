#
# @lc app=leetcode.cn id=120 lang=python3
#
# [120] 三角形最小路径和
#

# @lc code=start
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        # dp
        floors = len(triangle)
        if floors == 0:
            return 0
        for i in range(floors - 2, -1, -1):
            for j in range(i + 1):
                triangle[i][j] += min(triangle[i + 1][j + 1], triangle[i + 1][j])

        return triangle[0][0]
# @lc code=end

