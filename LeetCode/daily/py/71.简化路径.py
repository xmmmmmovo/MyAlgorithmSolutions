#
# @lc app=leetcode.cn id=71 lang=python3
#
# [71] 简化路径
#

# @lc code=start


class Solution:
    def simplifyPath(self, path: str) -> str:
        st = []
        c = ('.', '', '..')

        for s in path.split('/'):
            if s not in c:
                st.append(s)
            elif s == '..' and st:
                st.pop()

        return '/' + '/'.join(st)


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
    assert Solution().simplifyPath("/home/") == "/home"
    assert Solution().simplifyPath("/../") == "/"
    assert Solution().simplifyPath("/home//foo/") == "/home/foo"
    assert Solution().simplifyPath("/a/./b/../../c/") == "/c"
    assert Solution().simplifyPath("/a/../../b/../c//.//") == "/c"
    assert Solution().simplifyPath("/a//b////c/d//././/..") == "/a/b/c"
