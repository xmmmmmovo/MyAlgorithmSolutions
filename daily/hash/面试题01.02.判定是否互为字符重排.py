"""
给定两个字符串 s1 和 s2，请编写一个程序，
确定其中一个字符串的字符重新排列后，能否变成另一个字符串。

说明：

0 <= len(s1) <= 100
0 <= len(s2) <= 100
"""
from collections import Counter


class Solution:
    def CheckPermutation(self, s1: str, s2: str) -> bool:
        """
        这里不能用简单的ascii求和进行判断
        因为有可能和相等却不可以替换
        """
        if len(s1) != len(s2):
            return False

        return Counter(s1) == Counter(s2)


class Solution2:
    def CheckPermutation(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):
            return False

        return sorted(s1) == sorted(s2)


if __name__ == "__main__":
    print(Solution().CheckPermutation('abc', 'bca'))
    print(Solution().CheckPermutation('abc', 'bad'))
