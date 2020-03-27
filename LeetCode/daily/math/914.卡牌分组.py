#
# @lc app=leetcode.cn id=914 lang=python3
#
# [914] 卡牌分组
#

from typing import List

# @lc code=start

from collections import Counter
from math import gcd
from functools import reduce


class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        if len(deck) < 2:
            return False

        cd = Counter(deck).values()

        return reduce(gcd, cd) > 1
# @lc code=end


if __name__ == "__main__":
    assert Solution().hasGroupsSizeX([1, 2, 3, 4, 4, 3, 2, 1]) == True
    assert Solution().hasGroupsSizeX([1, 1, 1, 2, 2, 2, 3, 3]) == False
    assert Solution().hasGroupsSizeX([1]) == False
    assert Solution().hasGroupsSizeX([1, 1]) == True
    assert Solution().hasGroupsSizeX([1, 1, 2, 2, 2, 2]) == True
