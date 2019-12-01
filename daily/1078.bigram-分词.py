#
# @lc app=leetcode.cn id=1078 lang=python3
#
# [1078] Bigram 分词
#

# @lc code=start
class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        ans = []

        split_str = text.split()
        length = len(split_str)

        for k, s in enumerate(split_str[:-2]):
            if s == first and split_str[k + 1] == second:
                ans.append(split_str[k + 2])

        return ans
# @lc code=end

