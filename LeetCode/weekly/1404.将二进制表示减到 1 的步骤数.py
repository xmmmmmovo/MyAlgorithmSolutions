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
        res, idx = 0, len(s) - 1
        while idx > 0:
            if s[idx] == '0':
                # 如果是偶数直接右移一位
                res += 1
                idx -= 1
            else:
                res += 1
                while idx >= 0 and s[idx] == '1':
                    # 这里判断如果是1就直接进位
                    # 进位之后发现都是偶数 直接右移
                    res += 1
                    idx -= 1
                if idx > 0:
                    s[idx] = '1'
        
        return res



if __name__ == "__main__":
    assert Solution2().numSteps('1101') == 6
    assert Solution2().numSteps('10') == 1
    assert Solution2().numSteps('1') == 0
