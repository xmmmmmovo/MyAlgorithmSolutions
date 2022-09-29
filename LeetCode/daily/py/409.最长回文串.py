#
# @lc app=leetcode.cn id=409 lang=python3
#
# [409] 最长回文串
#

# @lc code=start

from collections import Counter


class Solution:
    def longestPalindrome(self, s: str) -> int:
        c = Counter(s)
        odd = True
        ans = 0

        for v in c.values():
            if v % 2 == 1 and odd:
                odd = False
                ans += 1
            ans += v // 2 * 2

        return ans

# @lc code=end


if __name__ == "__main__":
    assert Solution().longestPalindrome("abccccdd") == 7
