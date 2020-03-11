#
# @lc app=leetcode.cn id=1071 lang=python3
#
# [1071] 字符串的最大公因子
#

# @lc code=start

# math包里面自带gcd
from math import gcd


class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if str1 == str2:
            return str1

        # gcd 最后a就是gcd的值
        def gcd(a, b):
            while b:
                a, b = b, a % b
            return a

        g = gcd(len(str1), len(str2))

        if str1[:g]*(len(str1)//g) != str1 or str1[:g]*(len(str2)//g) != str2:
            return ''

        return str1[:g]


class Solution2:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        return '' if str1 + str2 != str2 + str1 else str1[:gcd(len(str1), len(str2))]
# @lc code=end


if __name__ == "__main__":
    print(Solution2().gcdOfStrings(str1="ABCABC", str2="ABC"))
    print(Solution2().gcdOfStrings(str1="ABABAB", str2="ABAB"))
    print(Solution2().gcdOfStrings(str1="LEET", str2="CODE"))
