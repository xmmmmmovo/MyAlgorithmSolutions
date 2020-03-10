#
# @lc app=leetcode.cn id=863 lang=python3
#
# [863] 二叉树中所有距离为 K 的结点
#

# @lc code=start
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def distanceK(self, root, target, K):
        """
        :type root: TreeNode
        :type target: TreeNode
        :type K: int
        :rtype: List[int]
        """
        from collections import deque
		
        # 判断是否是本身
        if not K:
            return [target.val]

        # dfs标记父节点
        def dfs(node: TreeNode, father_node: TreeNode):
            if node:
                node.father = father_node
                dfs(node.left, node)
                dfs(node.right, node)

        dfs(root, None)

        # 这一步过后其实就变成了图问题，每个都有三个节点的图
        # 下面对于target进行bfs
        def bfs():
            search = {target}
            queue = deque([(target, 0)])  # 存0 即原点
            while queue:
                if queue[0][1] == K:
                    return [node.val for node, N in queue]
                node, N = queue.popleft()
                for n in (node.left, node.right, node.father):
                    if n and n not in search:
                        queue.append((n, N + 1))
                        search.add(n)
            return []

        return bfs()
# @lc code=end

