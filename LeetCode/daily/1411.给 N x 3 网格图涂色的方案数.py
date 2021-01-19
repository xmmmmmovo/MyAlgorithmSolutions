

class Solution:
    def numOfWays(self, n: int) -> int:
        same, diff = 6, 6
        mod = int(1e9 + 7)
        # 这里从1开始算起 因n=1的可能性已经算过了
        for i in range(n-1):
            same, diff =\
                ((same * 3) % mod + (diff * 2) % mod) % mod,\
                ((same * 2) % mod + (diff * 2) % mod) % mod
        return (same + diff) % mod


if __name__ == "__main__":
    assert Solution().numOfWays(2) == 54
    assert Solution().numOfWays(3) == 246
    assert Solution().numOfWays(7) == 106494
    assert Solution().numOfWays(5000) == 30228214
