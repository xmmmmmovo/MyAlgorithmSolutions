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
        """
        盲猜dfs+剪枝
        """

        # 访问矩阵 用来判断是否已经访问
        vis = [[False for i in range(len(grid[0]))]
               for i in range(len(grid))]

        ans = 0
        tmp = 0

        def dfs(x, y):
            if grid[x][y] == 0:
                return
            if vis[x][y]:
                return
            vis[x][y] = True

            if 

            pass

        for (i, l) in enumerate(grid):
            for (j, v) in enumerate(l):
                if v == 1 and not vis[i][j]:
                    dfs()
                    pass
                pass

        pprint(vis)

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
