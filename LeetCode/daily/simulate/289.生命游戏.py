#
# @lc app=leetcode.cn id=289 lang=python3
#
#
from typing import List
from pprint import pprint

# @lc code=start


class Solution:
    def __init__(self):
        self.dirs = [(0, -1), (-1, -1), (-1, 0), (-1, 1),
                     (0, 1), (1, 1), (1, 0), (1, -1)]

    def cell_checker(self, board, i, j, k):
        cnt = 0
        for d in self.dirs:
            ii = i + d[0]
            jj = j + d[1]

            if ii == -1 or jj == -1 or ii == len(board) or jj == len(board[0]):
                continue

            cnt += 1 if abs(board[ii][jj]) == 1 else 0

        # pprint(f'k = {k} cnt = {cnt} i = {i} j = {j}')

        if k == 1 and (cnt < 2 or cnt > 3):
            return -1

        if k == 0 and cnt == 3:
            return 2

        return k

    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """

        for i in range(len(board)):
            for j in range(len(board[0])):
                board[i][j] = self.cell_checker(board, i, j, board[i][j])

        for i in range(len(board)):
            for j in range(len(board[0])):
                board[i][j] = 1 if board[i][j] > 0 else 0

# @lc code=end


if __name__ == "__main__":
    Solution().gameOfLife([
        [0, 1, 0],
        [0, 0, 1],
        [1, 1, 1],
        [0, 0, 0]
    ])
    Solution().gameOfLife([
        [0, 0, 0],
        [1, 0, 1],
        [0, 1, 1],
        [0, 1, 0]
    ])

