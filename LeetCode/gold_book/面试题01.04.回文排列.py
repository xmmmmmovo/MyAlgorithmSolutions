"""
给定一个字符串，编写一个函数判定其是否为某个回文串的排列之一。
回文串是指正反两个方向都一样的单词或短语。排列是指字母的重新排列。
回文串不一定是字典当中的单词。
"""
from collections import Counter


class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        dic = Counter(s)
        is_sig = False
        for v in dic.values():
            if v % 2 != 0:
                if is_sig:
                    return False
                else:
                    is_sig = True
        return True


class Solution2:
    def canPermutePalindrome(self, s: str) -> bool:
        c = set()
        for ch in s:
            if ch in c:
                c.remove(ch)
            else:
                c.add(ch)

        return len(c) <= 1


if __name__ == "__main__":
    print(Solution().canPermutePalindrome('tactcoa'))
    print(Solution().canPermutePalindrome('aab'))
