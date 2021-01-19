#
# @lc app=leetcode.cn id=1160 lang=python3
#
# [1160] 拼写单词
#

from typing import List

"""
注：
这个题也可以用26位数组来做(不用hash)
"""

# @lc code=start

from collections import Counter


class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        ans = 0
        c = Counter(chars)
        for w in words:
            cw = Counter(w)
            if not cw - (cw & c):
                ans += len(w)

        return ans


class Solution2:
    def countCharacters(self, words: List[str], chars: str) -> int:
        chars_cnt = Counter(chars)
        ans = 0
        for word in words:
            word_cnt = Counter(word)
            for c in word_cnt:
                if chars_cnt[c] < word_cnt[c]:
                    break
            else:
                ans += len(word)
        return ans

# @lc code=end


if __name__ == "__main__":
    print(Solution().countCharacters(
        words=["cat", "bt", "hat", "tree"], chars="atach"))
    print(Solution().countCharacters(
        words=["hello", "world", "leetcode"], chars="welldonehoneyr"))
