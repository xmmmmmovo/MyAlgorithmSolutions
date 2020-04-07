class Solution:
    def numSteps(self, s: str) -> int:
        i = int(s, 2)
        st = 0
        while i != 1:
            if i % 2 == 0:
                i = i//2
            else:
                i += 1
            st += 1
        return st


class Solution2:
    def numSteps(self, s: str) -> int:
        """
        不转string
        模拟位操作
        注:对于2这个数字要敏感
        """
        res, up = 0, 0

        for i in range(len(s) - 1, 0, -1):
            res += 2 if up ^ (s[i] == '1') else 1
            up = 1 if up or (s[i] == '1') else 0

        return res + 1 if up else res


if __name__ == "__main__":
    assert Solution2().numSteps('1101') == 6
    assert Solution2().numSteps('10') == 1
    assert Solution2().numSteps('1') == 0
