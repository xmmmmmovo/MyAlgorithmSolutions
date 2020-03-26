#
# @lc app=leetcode.cn id=824 lang=python3
#
# [824] 山羊拉丁文
#

# @lc code=start
class Solution:
    def toGoatLatin(self, S: str) -> str:
        vowel = "aeiouAEIOU"

        spllit_str = S.split(" ")
        for k, s in enumerate(spllit_str):
            if s[0] not in vowel:
                s = s[1:] + s[0]
            s += "ma" + "a" * (k + 1)
            spllit_str[k] = s

        return ' '.join(spllit_str)
# @lc code=end

