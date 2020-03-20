#
# @lc app=leetcode.cn id=365 lang=python3
#
# [365] 水壶问题
#

# @lc code=start
from math import gcd


class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        """
        抽象深搜/广搜
        """
        stack = [(0, 0)]
        seen = set()
        while stack:
            rx, ry = stack.pop()
            # 判断是否可以
            if rx == z or ry == z or rx + ry == z:
                return True

            if (rx, ry) in seen:
                continue

            seen.add((rx, ry))
            # x倒空
            stack.append((0, ry))
            # y倒空
            stack.append((rx, 0))
            # x倒满
            stack.append((x, ry))
            # y倒满
            stack.append((rx, y))
            # x倒入y
            stack.append((max(0, rx - y + ry), ry + min(rx, y - ry)))
            # y倒入x
            stack.append((rx + min(ry, x - rx), max(0, ry - x + rx)))

        return False


class Solution2:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        """
        数学解法(贝祖定理)(数论)
        若a,b是整数,且gcd(a,b)=d，
        那么对于任意的整数x, y, ax+by都一定是d的倍数，
        特别地，一定存在整数x,y，使ax+by=d成立
        """

        # 在这里a,b是系数 x,y是参数 构建ax + by = z
        if x + y < z:
            return False

        if x == 0 or y == 0:
            return z == 0 or x + y == z

        return z % gcd(x, y) == 0


# @lc code=end
if __name__ == "__main__":
    assert Solution().canMeasureWater(x=3, y=5, z=4) == True
    assert Solution().canMeasureWater(x=2, y=6, z=5) == False
    assert Solution().canMeasureWater(x=0, y=0, z=0) == True
    assert Solution().canMeasureWater(x=4, y=6, z=8) == True
