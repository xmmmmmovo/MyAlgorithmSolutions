from typing import List


class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        l = len(matrix)
        tmp = [[0] * l for _ in range(l)]

        for i in range(l):
            for j in range(l):
                tmp[j][l - i - 1] = matrix[i][j]

        matrix[:] = tmp


class Solution2:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        l = len(matrix)
        for i in range(l // 2):
            matrix[i], matrix[l - i - 1] = matrix[l - i - 1], matrix[i]

        for i in range(l):
            for j in range(i):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

if __name__ == "__main__":
    Solution2().rotate([
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ])
