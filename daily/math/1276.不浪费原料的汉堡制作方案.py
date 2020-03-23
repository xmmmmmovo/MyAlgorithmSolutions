from typing import List

class Solution:
    def numOfBurgers(self, tomatoSlices: int, cheeseSlices: int) -> List[int]:
        """
            巨无霸汉堡：4 片番茄和 1 片奶酪
            小皇堡：2 片番茄和 1 片奶酪
        """
        big_burgers = int((tomatoSlices - 2 * cheeseSlices) / 2)
        lite_burgers = int((4 * cheeseSlices - tomatoSlices) / 2)

        if big_burgers < 0 or lite_burgers < 0 or 4 * big_burgers + 2 * lite_burgers != tomatoSlices:
            return []

        return [big_burgers, lite_burgers]


if __name__ == "__main__":
    s = Solution()
    print(s.numOfBurgers(16, 7))
    print(s.numOfBurgers(17, 4))
    print(s.numOfBurgers(4, 17))
    print(s.numOfBurgers(0, 0))
    print(s.numOfBurgers(2, 1))