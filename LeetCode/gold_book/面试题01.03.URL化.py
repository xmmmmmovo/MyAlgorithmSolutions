"""
URL化。编写一种方法，将字符串中的空格全部替换为%20。
假定该字符串尾部有足够的空间存放新增字符，并且知道字符串的“真实”长度。

提示：

字符串长度在[0, 500000]范围内。
"""


class Solution:
    def replaceSpaces(self, S: str, length: int) -> str:
        return S[:length].replace(' ', '%20')


if __name__ == "__main__":
    print(Solution().replaceSpaces('Mr John Smith    ', 13))
    print(Solution().replaceSpaces('               ', 5))
