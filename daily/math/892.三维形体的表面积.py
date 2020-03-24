#
# @lc app=leetcode.cn id=892 lang=python3
#
# [892] 三维形体的表面积
#

from typing import List

# @lc code=start


class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        ans = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                ans += 2 if grid[i][j] != 0 else 0
                ans += grid[i][j] if i == 0 else max(
                    grid[i][j] - grid[i-1][j], 0
                )
                ans += grid[i][j] if j == 0 else max(
                    grid[i][j] - grid[i][j-1], 0
                )

                ans += grid[i][j] if i == len(grid) - 1 else max(
                    grid[i][j] - grid[i+1][j], 0
                )
                ans += grid[i][j] if j == len(grid[0]) - 1 else max(
                    grid[i][j] - grid[i][j+1], 0
                )

        return ans


class Solution2:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        N = len(grid)

        ans = 0
        for r in range(N):
            for c in range(N):
                # 这里提前判断可以节省时间
                if grid[r][c]:
                    ans += 2
                    for nr, nc in ((r-1, c), (r+1, c), (r, c-1), (r, c+1)):
                        if 0 <= nr < N and 0 <= nc < N:
                            nval = grid[nr][nc]
                        else:
                            nval = 0

                        ans += max(grid[r][c] - nval, 0)

        return ans
# @lc code=end


if __name__ == "__main__":
    assert Solution().surfaceArea([[2]]) == 10
    assert Solution().surfaceArea([[1, 2], [3, 4]]) == 34
    assert Solution().surfaceArea([[1, 0], [0, 2]]) == 16
    assert Solution().surfaceArea([[1, 1, 1], [1, 0, 1], [1, 1, 1]]) == 32
    assert Solution().surfaceArea([[2, 2, 2], [2, 1, 2], [2, 2, 2]]) == 46
