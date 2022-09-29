#
# @lc app=leetcode.cn id=820 lang=python3
#
# [820] 单词的压缩编码
#

from typing import List

# @lc code=start

from collections import defaultdict
from functools import reduce


class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        """
        反转后缀排序判断
        o(n∑len(wi))
        """
        res = 0
        # 这里先转set去重 可以省不少时间
        words = list(set(words))
        words.sort(key=lambda w: w[::-1])

        for i in range(len(words)):
            if i+1 < len(words) and words[i+1].endswith(words[i]):
                pass
            else:
                res += len(words[i]) + 1
        return res


class Solution2:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        """
        字典树解法
        单词倒序可以存字典树
        算叶子节点深度
        """
        words = list(set(words))

        # 命名lambda
        def Trie(): return defaultdict(Trie)
        # 相当于一个套娃 就是一个字典里面套另一个lambda
        trie = Trie()

        #reduce(..., S, trie) is trie[S[0]][S[1]][S[2]][...][S[S.length - 1]]
        nodes = [reduce(dict.__getitem__, word[::-1], trie)
                 for word in words]

        # Add word to the answer if it's node has no neighbors
        return sum(len(word) + 1
                   for i, word in enumerate(words)
                   if len(nodes[i]) == 0)
# @lc code=end


if __name__ == "__main__":
    assert Solution2().minimumLengthEncoding(["time", "me", "bell"]) == 10
