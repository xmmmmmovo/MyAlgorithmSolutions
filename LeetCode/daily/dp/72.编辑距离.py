#
# @lc app=leetcode.cn id=72 lang=python3
#
# [72] 编辑距离
#

# @lc code=start


class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        wl1, wl2 = len(word1), len(word2)

        if wl1 * wl2 == 0:
            return wl1 + wl2

        # 因为要考虑空字符串的缘故所以要+1后面的都需要+1
        dp = [[0] * (wl2 + 1) for _ in range(wl1 + 1)]
        print(dp)
        for i in range(1, wl1 + 1):
            dp[i][0] = i

        for i in range(1, wl2 + 1):
            dp[0][i] = i

        for i in range(1, wl1 + 1):
            for j in range(1, wl2 + 1):
                # 这里-1是因为上面dp数组+1了
                if word1[i - 1] == word2[j - 1]:
                    # 这时候不需要任何操作可以直接切向下一个
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    # 插入 删除 替换
                    dp[i][j] = min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1])+1

        return dp[-1][-1]
# @lc code=end


if __name__ == "__main__":
    # assert Solution().minDistance(word1="horse", word2="ros") == 3
    # assert Solution().minDistance(word1="intention", word2="execution") == 5
    assert Solution().minDistance(word1="a", word2="b") == 1
