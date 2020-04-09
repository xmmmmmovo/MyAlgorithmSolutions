#
# @lc app=leetcode.cn id=22 lang=python3
#
# [22] 括号生成
#
from typing import List
# @lc code=start


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []

        def calculate(ls, l, r):
            """
            l: 左括号数量
            r: 右括号数量
            """
            if len(ls) == 2 * n:
                res.append(''.join(ls))
                return

            if l < n:
                ls.append('(')
                calculate(ls, l + 1, r)
                ls.pop()

            if r < l:
                ls.append(')')
                calculate(ls, l, r + 1)
                ls.pop()

        calculate([], 0, 0)
        return res

# @lc code=end


if __name__ == "__main__":
    assert Solution().generateParenthesis(3) == [
        "((()))",
        "(()())",
        "(())()",
        "()(())",
        "()()()"
    ]
