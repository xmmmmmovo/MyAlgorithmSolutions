/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x),
 * left(left), right(right) {}
 * };
 */
class Solution {
  public:
    void insert_nodes(TreeNode *node, int val, int depth) {
        if (node == nullptr)
            return;
        if (depth == 1) {
            node->left  = new TreeNode(val, node->left, nullptr);
            node->right = new TreeNode(val, nullptr, node->right);
        } else {
            insert_nodes(node->left, val, depth - 1);
            insert_nodes(node->right, val, depth - 1);
        }
    }

    TreeNode *addOneRow(TreeNode *root, int val, int depth) {
        if (root == nullptr)
            return root;
        if (depth == 1) {
            TreeNode *n = new TreeNode(val, root, nullptr);
            return n;
        }
        insert_nodes(root, val, depth - 1);
        return root;
    }
};