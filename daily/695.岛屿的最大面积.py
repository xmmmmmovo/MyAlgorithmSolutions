#
# @lc app=leetcode.cn id=695 lang=python3
#
# [695] 岛屿的最大面积
#

from pprint import pprint
from typing import List

# @lc code=start


class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        pprint(grid)
        pass

# @lc code=end


print(Solution().maxAreaOfIsland([[0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
                                  [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
                                  [0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
                                  [0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0],
                                  [0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0],
                                  [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0],
                                  [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
                                  [0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0]]))

print(Solution().maxAreaOfIsland([[0, 0, 0, 0, 0, 0, 0, 0]]))
