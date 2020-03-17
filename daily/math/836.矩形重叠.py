#
# @lc app=leetcode.cn id=836 lang=python3
#
# [836] 矩形重叠
#

from typing import List

# @lc code=start


class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        return (max(rec1[0], rec2[0]) < min(rec1[2], rec2[2])) and (max(rec1[1], rec2[1]) < min(rec1[3], rec2[3]))


class Solution2:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        """
        穷举四种不存在重叠的情况 剩余便都是重叠情况
        """
        return not (rec1[2] <= rec2[0] or  # left
                    rec1[3] <= rec2[1] or  # bottom
                    rec1[0] >= rec2[2] or  # right
                    rec1[1] >= rec2[3])    # top


# @lc code=end


if __name__ == "__main__":
    print(Solution().isRectangleOverlap(rec1=[0, 0, 2, 2], rec2=[1, 1, 3, 3]))
    print(Solution().isRectangleOverlap(rec1=[0, 0, 1, 1], rec2=[1, 0, 2, 1]))
