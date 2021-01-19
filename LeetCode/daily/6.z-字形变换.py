#
# @lc app=leetcode.cn id=6 lang=python3
#
# [6] Z 字形变换
#

# @lc code=start


class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if s == '' or numRows == 1:
            return s

        ans_list = [[] for j in range(numRows)]

        mid_lines = numRows - 2
        filter_num = len(s) / (numRows + mid_lines)
        count = 0
        slen = len(s)

        def ret():
            ans = ''
            for i in range(numRows):
                ans += ''.join(ans_list[i])

            return ans

        for k in range(int(filter_num) + 1):

            for i in range(numRows):
                ans_list[i].append(s[count])
                count += 1
                if count >= slen:
                    return ret()

            for add_row in range(mid_lines):
                ans_list[mid_lines - add_row].append(s[count])
                count += 1
                if count >= slen:
                    return ret()

        return ret()


class Solution2:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s

        r = ['' for i in range(min(numRows, len(s)))]
        cur = 0
        # 判断是下降排还是上升排
        down = False

        for ch in s:
            r[cur] += ch
            if cur == 0 or cur == numRows - 1:
                down = not down
            # 如果是降就该升了
            cur += 1 if down else -1

        return ''.join(r)


# @lc code=end
s = Solution2()

print(s.convert('LEETCODEISHIRING', 3))

print(s.convert('LEETCODEISHIRING', 4))
