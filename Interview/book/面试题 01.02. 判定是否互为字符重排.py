from collections import Counter


class Solution:
    def CheckPermutation(self, s1: str, s2: str) -> bool:
        """
        这里不能用简单的ascii求和进行判断
        因为有可能和相等却不可以替换
        """
        if len(s1) != len(s2):
            return False

        return Counter(s1) == Counter(s2)


class Solution2:
    def CheckPermutation(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):
            return False

        return sorted(s1) == sorted(s2)


if __name__ == "__main__":
    print(Solution().CheckPermutation('abc', 'bca'))
    print(Solution().CheckPermutation('abc', 'bad'))
