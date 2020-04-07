#
# @lc app=leetcode.cn id=8 lang=python3
#
# [8] 字符串转换整数 (atoi)
#

import re

# @lc code=start


class Solution2:
    def __init__(self):
        self.state = 0
        self.sign = 1
        self.ans = 0
        self.status = [
            [0, 1, 2, 3],
            [3, 3, 2, 3],
            [3, 3, 2, 3],
            [3, 3, 3, 3]
        ]
        self.table = {
            'start': ['start', 'signed', 'in_number', 'end'],
            'signed': ['end', 'end', 'in_number', 'end'],
            'in_number': ['end', 'end', 'in_number', 'end'],
            'end': ['end', 'end', 'end', 'end'],
        }

    def get_col(self, c):
        if c.isspace():
            return 0
        if c == '+' or c == '-':
            return 1
        if c.isdigit():
            return 2
        return 3

    def get(self, c):
        self.state = self.status[self.state][self.get_col(c)]
        if self.state == 2:
            self.ans = self.ans * 10 + int(c)
            self.ans = min(self.ans, 2147483647 if self.sign ==
                           1 else 2147483648)
        elif self.state == 1:
            self.sign = 1 if c == '+' else -1

    def myAtoi(self, str: str) -> int:
        """
        有限状态机DFA
        """
        for c in str:
            self.get(c)
        return self.ans * self.sign


class Solution3:
    def myAtoi(self, str: str) -> int:
        """
        正则解法
        """
        return max(min(int(*re.findall(r'^[\+\-]?\d+', str.lstrip())), 2147483647), -2147483648)
# @lc code=end


if __name__ == "__main__":
    assert Solution2().myAtoi("42") == 42
    assert Solution2().myAtoi("   -42") == -42
    assert Solution2().myAtoi("4193 with words") == 4193
    assert Solution2().myAtoi("words and 987") == 0
    assert Solution2().myAtoi("-91283472332") == -2147483648
