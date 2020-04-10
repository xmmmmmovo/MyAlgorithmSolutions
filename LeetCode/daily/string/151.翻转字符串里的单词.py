#
# @lc app=leetcode.cn id=151 lang=python3
#
# [151] 翻转字符串里的单词
#

# @lc code=start

from collections import deque


class Solution:
    def reverseWords(self, s: str) -> str:
        return ' '.join(reversed(s.split()))


class Solution2:
    def reverseWords(self, s: str) -> str:
        """
        双端队列解法
        """
        l, r = 0, len(s) - 1
        while l < r and s[l] == ' ':
            l += 1

        while l < r and s[r] == ' ':
            r -= 1

        d, w = deque(), ''
        while l <= r:
            if s[l] != ' ':
                w += s[l]
            elif w:
                d.appendleft(w)
                w = ''
            l += 1
        d.appendleft(w)
        return ' '.join(d)
# @lc code=end


if __name__ == "__main__":
    assert Solution2().reverseWords("the sky is blue") == "blue is sky the"
    assert Solution2().reverseWords("  hello world!  ") == "world! hello"
    assert Solution2().reverseWords("a good   example") == "example good a"
