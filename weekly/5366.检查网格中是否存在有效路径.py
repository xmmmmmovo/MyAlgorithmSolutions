from typing import List


class Solution:
    def hasValidPath(self, grid: List[List[int]]) -> bool:
        y = len(grid)
        x = len(grid[0])

        vis = [[False for _ in range(x)] for _ in range(y)]
        mapper = [[1, 0, 1, 0],
                  [0, 1, 0, 1],
                  [1, 0, 0, 1],
                  [0, 0, 1, 1],
                  [1, 1, 0, 0],
                  [0, 1, 1, 0]]
        

        pass


if __name__ == "__main__":
    assert Solution().hasValidPath([[1, 2, 1], [1, 2, 1]]) == False
    assert Solution().hasValidPath([[1, 1, 1, 1, 1, 1, 3]]) == True
    assert Solution().hasValidPath([[2], [2], [2], [2], [2], [2], [6]]) == True
