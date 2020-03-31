#
# @lc app=leetcode.cn id=1111 lang=python3
#
# [1111] 有效括号的嵌套深度
#

from typing import List

# @lc code=start


class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        res = []
        deep = 0

        for s in seq:
            if s == '(':
                deep += 1
                res.append(deep % 2)
            else:
                # 这里要先匹配再减深度
                res.append(deep % 2)
                deep -= 1

        return res

# @lc code=end


if __name__ == "__main__":
    assert Solution().maxDepthAfterSplit("(()())") == [0, 1, 1, 1, 1, 0]
    assert Solution().maxDepthAfterSplit(
        "()(())()") == [0, 0, 0, 1, 1, 0, 1, 1]
