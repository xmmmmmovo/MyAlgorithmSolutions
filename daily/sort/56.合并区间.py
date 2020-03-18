#
# @lc app=leetcode.cn id=56 lang=python3
#
# [56] 合并区间
#

from typing import List

# @lc code=start


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals:
            return []

        intervals.sort()
        ans = [intervals[0]]
        for i in range(len(intervals) - 1):
            if intervals[i+1][0] > ans[-1][1]:
                ans.append(intervals[i+1])
            else:
                if ans[-1][1] < intervals[i+1][1]:
                    ans[-1][1] = intervals[i+1][1]

        return ans
# @lc code=end


if __name__ == "__main__":
    assert Solution().merge([[1, 3], [2, 6], [8, 10], [15, 18]]) == [
        [1, 6], [8, 10], [15, 18]]
    assert Solution().merge([[1, 4], [4, 5]]) == [[1, 5]]
    assert Solution().merge([[1, 4], [2, 3]]) == [[1, 4]]
    assert Solution().merge(
        [[2, 3], [4, 5], [6, 7], [8, 9], [1, 10]]) == [[1, 10]]
