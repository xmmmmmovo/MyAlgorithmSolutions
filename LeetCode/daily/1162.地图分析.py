#
# @lc app=leetcode.cn id=1162 lang=python3
#
# [1162] 地图分析
#

# @lc code=start


class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        dirs = [(0, -1), ()]
        pass
# @lc code=end


if __name__ == "__main__":
    assert Solution().maxDistance([[1, 0, 1], [0, 0, 0], [1, 0, 1]]) == 2
    assert Solution().maxDistance([[1, 0, 0], [0, 0, 0], [0, 0, 0]]) == 4
