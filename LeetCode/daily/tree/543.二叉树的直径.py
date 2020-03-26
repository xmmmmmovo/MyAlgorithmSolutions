#
# @lc app=leetcode.cn id=543 lang=python3
#
# [543] 二叉树的直径
#

# @lc code=start
# Definition for a binary tree node.


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        """
        这里不能简单的利用root的左右子树来判断最大值
        反例:
        [4,-7,-3,null,null,-9,-3,9,-7,-4,null,6,null,-6,-6,null,null,0,6,5,null,9,null,null,-1,-4,null,null,null,-2]
        """
        max_w = 0

        def dep(node):
            nonlocal max_w
            if node is None:
                return 0

            left_w = dep(node.left)
            right_w = dep(node.right)

            # 判断左子树+右子树之和是否比max大
            max_w = max(max_w, left_w + right_w)

            return max(left_w, right_w) + 1

        dep(root)
        return max_w

# @lc code=end
