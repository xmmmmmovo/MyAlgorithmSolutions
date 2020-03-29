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


if __name__ == "__main__":
    assert Solution().numTeams([2, 5, 3, 4, 1]) == 3
    assert Solution().numTeams([2, 1, 3]) == 0
    assert Solution().numTeams([1, 2, 3, 4]) == 4
