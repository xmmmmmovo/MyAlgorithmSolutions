#
# @lc app=leetcode.cn id=71 lang=python3
#
# [71] 简化路径
#

# @lc code=start


class Solution:
    def simplifyPath(self, path: str) -> str:

        pass


class Solution2:
    def simplifyPath(self, path: str) -> str:
        """
        4行python解法
        from Knife丶👆👆👆
        """
        r = []
        for s in path.split('/'):
            r = {'': r, '.': r, '..': r[:-1]}.get(s, r + [s])
        return '/' + '/'.join(r)
# @lc code=end


if __name__ == "__main__":
    print(Solution().simplifyPath("/home/"))
    print(Solution().simplifyPath("/../"))
    print(Solution().simplifyPath("/home//foo/"))
    print(Solution().simplifyPath("/a/./b/../../c/"))
    print(Solution().simplifyPath("/a/../../b/../c//.//"))
    print(Solution().simplifyPath("/a//b////c/d//././/.."))
