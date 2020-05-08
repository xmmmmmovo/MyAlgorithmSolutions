from typing import List


class Solution:
    def minTime(self, time: List[int], m: int) -> int:
        res = 0
        if len(time) < m:
            return 0

        l, r = 0, len(time) - 1
        cnt = 0

        while l < r:
            if cnt < m:
                cnt += 1
            else:
                break
            mid = (l + r) // 2
            ls = sum(time[:mid]) - max(time[:mid])
            rs = sum(time[mid:]) - max(time[mid:])
            if ls > rs:
                res = min(res, rs)
                r = mid - 1
            else:
                res = min(res, ls)
                l = mid

            print(res)


if __name__ == "__main__":
    assert Solution().minTime(time=[1, 2, 3, 3], m=2) == 3
    assert Solution().minTime(time=[999, 999, 999], m=4) == 0
