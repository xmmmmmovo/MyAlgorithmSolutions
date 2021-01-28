"""
面试题 01.06. 字符串压缩
字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。
比如，字符串aabcccccaaa会变为a2b1c5a3。
若“压缩”后的字符串没有变短，则返回原先的字符串。
你可以假设字符串中只包含大小写英文字母（a至z）。

示例1:
 输入："aabcccccaaa"
 输出："a2b1c5a3"
示例2:
 输入："abbccd"
 输出："abbccd"
 解释："abbccd"压缩后为"a1b2c2d1"，比原字符串长度更长。

字符串长度在[0, 50000]范围内。
"""


class Solution:
    def compressString(self, S: str) -> str:
        if not S:
            return ''

        ans = ''
        ch_tmp = S[0]
        cnt = 0

        for ch in S:
            if ch_tmp == ch:
                cnt += 1
            else:
                ans += ch_tmp + str(cnt)
                ch_tmp = ch
                cnt = 1

        ans += ch_tmp + str(cnt)

        return ans if len(ans) < len(S) else S


if __name__ == "__main__":
    print(Solution().compressString("aabcccccaaa"))
    print(Solution().compressString("abbccd"))
    print(Solution().compressString("aabcccccaa"))
