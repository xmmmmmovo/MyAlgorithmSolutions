#
# @lc app=leetcode.cn id=6 lang=python3
#
# [6] Z 字形变换
#

# @lc code=start

class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        
        slen = len(s)
        ans_list = ['' for i in range(numRows)]

        # 每次迭代numRows个
        for i in range(0, slen, numRows):
            try:
                pass
            except:
                pass



        return ''

# @lc code=end


s = Solution()

print(s.convert('LEETCODEISHIRING', 3))

print(s.convert('LEETCODEISHIRING', 4))
