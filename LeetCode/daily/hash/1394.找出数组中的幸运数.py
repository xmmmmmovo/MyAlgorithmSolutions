from typing import List
from collections import Counter


class Solution:
    def findLucky(self, arr: List[int]) -> int:
        try:return max(k for k, v in Counter(arr).items() if k == v)
        except:return -1


if __name__ == "__main__":
    assert Solution().findLucky([2, 2, 3, 4]) == 2
    assert Solution().findLucky([2, 2, 2, 3, 3]) == -1
