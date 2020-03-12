"""
字符串有三种编辑操作:插入一个字符、删除一个字符或者替换一个字符。 
给定两个字符串，编写一个函数判定它们是否只需要一次(或者零次)编辑。
"""


class Solution:
    def oneEditAway(self, first: str, second: str) -> bool:
        if abs(len(first) - len(second)) > 1:
            return False

        i, j = 0, 0
        c = 0

        while i < len(first) and j < len(second):
            if first[i] == second[j]:
                i += 1
                j += 1
            elif True:
                pass
        pass


if __name__ == "__main__":
    print(Solution().oneEditAway('pale', 'ple'))
    print(Solution().oneEditAway('pales', 'pal'))
