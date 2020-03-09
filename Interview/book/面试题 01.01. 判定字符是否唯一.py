class Solution:
    def isUnique(self, astr: str) -> bool:
        chs = set()

        for ch in astr:
            if ch in chs:
                return False

            chs.add(ch)

        return True


class Solution2:
    def isUnique(self, astr: str) -> bool:
        """
        这个是上个solution的简化操作
        """
        return len(set(astr)) == len(astr)


class Solution3:
    def isUnique(self, astr: str) -> bool:
        """
        这个是用位运算的版本
        这里是利用一个int类型的变量相当于01bool类型的数组
        总共26个位便可以模拟
        为什么可以用：
        因为这个题总结起来是需要非重复字符串 所以可以1/0这么写
        """
        mark = 0
        for ch in astr:
            # 需要位移的位数
            move_bit = ord(ch) - ord('a')
            # 1位移到了相关的位数之后进行与运算判断那位是否是0
            if (mark & (1 << move_bit)) != 0:
                return False
            else:
                # 否则将那位置1
                mark |= (1 << move_bit)

        return True


if __name__ == "__main__":
    print(Solution().isUnique('leetcode'))
    print(Solution().isUnique('abc'))
