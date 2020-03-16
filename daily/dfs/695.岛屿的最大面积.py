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
        dfs+剪枝
        但其实这个题目用bfs也可以
        懒得写了
        """

        ylen = len(grid[0])
        xlen = len(grid)

        # 访问矩阵 用来判断是否已经访问
        vis = [[False for i in range(ylen)]
               for i in range(xlen)]

        ans = 0
        tmp = 0

        def dfs(x, y):
            nonlocal tmp

            if x < 0 or y < 0 or x >= xlen or y >= ylen:
                return
            if not grid[x][y]:
                return
            if vis[x][y]:
                return
            vis[x][y] = True

            if grid[x][y]:
                tmp += 1

            dfs(x+1, y)
            dfs(x-1, y)
            dfs(x, y+1)
            dfs(x, y-1)

        for (i, l) in enumerate(grid):
            for (j, v) in enumerate(l):
                if v == 1 and not vis[i][j]:
                    dfs(i, j)
                    ans = max(ans, tmp)
                    tmp = 0

        return ans


# @lc code=end


if __name__ == "__main__":
    print(Solution().maxAreaOfIsland([[0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
                                      [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
                                      [0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
                                      [0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0],
                                      [0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0],
                                      [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0],
                                      [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
                                      [0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0]]))

    print(Solution().maxAreaOfIsland([[0, 0, 0, 0, 0, 0, 0, 0]]))
