#
# @lc app=leetcode.cn id=1162 lang=python3
#
# [1162] 地图分析
#

from typing import List

# @lc code=start


class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        """
        bfs
        """
        dirs = [(0, -1), ()]
        pass


class Solution2:
    def maxDistance(self, grid: List[List[int]]) -> int:
        """
        dp
        """
        dirs = [(0, -1), ()]
        pass

# @lc code=end


if __name__ == "__main__":
    assert Solution().maxDistance([[1, 0, 1], [0, 0, 0], [1, 0, 1]]) == 2
    assert Solution().maxDistance([[1, 0, 0], [0, 0, 0], [0, 0, 0]]) == 4
