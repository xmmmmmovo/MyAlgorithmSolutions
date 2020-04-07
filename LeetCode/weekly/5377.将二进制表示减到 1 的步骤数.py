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


if __name__ == "__main__":
    assert Solution().numSteps('1101') == 6
    assert Solution().numSteps('10') == 1
    assert Solution().numSteps('1') == 0
