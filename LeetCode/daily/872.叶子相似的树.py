#
# @lc app=leetcode.cn id=872 lang=python3
#
# [872] 叶子相似的树
#

# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:
        # 前序遍历
        def tree_leaf_sim_calcu(root: TreeNode):
            stack, ans = [], []  # 用list
            while len(stack) or root:
                if root:
                    if root.left is root.right is None:
                        ans.append(root.val)
                    stack.append(root)
                    root = root.left
                else:
                    root = stack.pop().right
            return ans

        return tree_leaf_sim_calcu(root1) == tree_leaf_sim_calcu(root2)
# @lc code=end

