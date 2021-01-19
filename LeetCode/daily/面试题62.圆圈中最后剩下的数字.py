class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        """
        约瑟夫环
        https://blog.csdn.net/u011500062/article/details/72855826
        """
        f = 0
        for i in range(2, n+1):
            f = (m + f) % i
        return f
