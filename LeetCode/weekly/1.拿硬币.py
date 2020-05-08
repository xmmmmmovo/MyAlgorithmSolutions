from typing import List

class Solution:
    def minCount(self, coins: List[int]) -> int:
        res = 0
        for c in coins:
            res += c // 2 + c % 2
        return res


if __name__ == "__main__":
    assert Solution().minCount([4, 2, 1]) == 4
    assert Solution().minCount([2, 3, 10]) == 8
