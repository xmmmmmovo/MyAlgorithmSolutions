"""
5356. 矩阵中的幸运数
给你一个 m * n 的矩阵，矩阵中的数字各不相同 。
请你按 任意 顺序返回矩阵中的所有幸运数。

幸运数是指矩阵中满足同时下列两个条件的元素：

在同一行的所有元素中最小
在同一列的所有元素中最大
"""

from typing import List


class Solution:
    def luckyNumbers(self, matrix: List[List[int]]) -> List[int]:
        ans = []

        for i in range(len(matrix)):
            fit = True
            j = matrix[i].index(min(matrix[i]))
            for k in range(len(matrix)):
                # print(k)
                if matrix[k][j] > matrix[i][j]:
                    fit = False

            if fit:
                ans.append(matrix[i][j])

        return ans


if __name__ == "__main__":
    print(Solution().luckyNumbers([[3, 7, 8], [9, 11, 13], [15, 16, 17]]))
    print(Solution().luckyNumbers(
        [[1, 10, 4, 2], [9, 3, 8, 7], [15, 16, 17, 12]]))
    print(Solution().luckyNumbers([[7, 8], [1, 2]]))
