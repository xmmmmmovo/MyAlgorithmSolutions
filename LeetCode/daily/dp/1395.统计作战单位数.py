from typing import List


class Solution:
    def numTeams(self, rating: List[int]) -> int:
        res = 0
        for i in range(len(rating) - 2):
            for j in range(i+1, len(rating)-1):
                for k in range(j+1, len(rating)):
                    if (rating[i] < rating[j] and rating[j] < rating[k]) or (rating[i] > rating[j] and rating[j] > rating[k]):
                        res += 1

        return res


class Solution2:
    def numTeams(self, rating: List[int]) -> int:
        """
        整体思想是遍历每个节点查看其本身可以当成中间节点的所有可能
        """
        if len(rating) < 3:
            return 0
        res = 0

        for j in range(len(rating) - 1):
            scl = 0
            scr = 0
            bcl = 0
            bcr = 0
            for i in range(j):
                if(rating[i] < rating[j]):
                    scl += 1
                else:
                    bcl += 1

            for k in range(j+1, len(rating)):
                if(rating[k] < rating[j]):
                    scr += 1
                else:
                    bcr += 1

            res += scl * bcr + bcl * scr  # 左小右大 左大右小

        return res


if __name__ == "__main__":
    assert Solution2().numTeams([2, 5, 3, 4, 1]) == 3
    assert Solution2().numTeams([2, 1, 3]) == 0
    assert Solution2().numTeams([1, 2, 3, 4]) == 4
