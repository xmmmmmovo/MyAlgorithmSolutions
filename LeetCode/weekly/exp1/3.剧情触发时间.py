from typing import List
from pprint import pprint


class Solution:
    def getTriggerTime(self, increase: List[List[int]], requirements: List[List[int]]) -> List[int]:
        res = [-1 for _ in range(len(requirements))]
        d = {}

        pprint(requirements)
        requirements.sort()
        pprint(requirements)

        for (k, r) in enumerate(requirements):
            if r[0] == 0 and r[1] == 0 and r[2] == 0:
                res[k] = 0
            else:
                d[k] = r

        t = [0, 0, 0]
        for (i, day) in enumerate(increase):
            t[0] += day[0]
            t[1] += day[1]
            t[2] += day[2]

            for k in list(d.keys()):
                r = d[k]
                if res[k] == -1 and r[0] <= t[0] and r[1] <= t[1] and r[2] <= t[2]:
                    del d[k]
                    res[k] = i+1

        return res


if __name__ == "__main__":
    assert Solution().getTriggerTime(increase=[[2, 8, 4], [2, 5, 0], [10, 9, 8]], requirements=[
        [2, 11, 3], [15, 10, 7], [9, 17, 12], [8, 1, 14]]) == [2, -1, 3, -1]
    assert Solution().getTriggerTime(increase=[[0, 4, 5], [4, 8, 8], [8, 6, 1], [10, 10, 0]], requirements=[
        [12, 11, 16], [20, 2, 6], [9, 2, 6], [10, 18, 3], [8, 14, 9]]) == [-1, 4, 3, 3, 3]
    assert Solution().getTriggerTime(
        increase=[[1, 1, 1]], requirements=[[0, 0, 0]]) == [0]
