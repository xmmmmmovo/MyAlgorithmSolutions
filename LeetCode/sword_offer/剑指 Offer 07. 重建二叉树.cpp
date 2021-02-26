/**
 * author: xmmmmmovo
 * generation time: 2021/02/26
 * filename: 剑指 Offer 07. 重建二叉树.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode {
    int       val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    vector<int>             preorder;
    unordered_map<int, int> dic; // 相当于标记后中序遍历

    TreeNode *recur(int root, int left, int right) {
        if (left > right)
            return nullptr;
        TreeNode *node = new TreeNode(preorder[root]);
        int       i    = dic[preorder[root]];
        node->left     = recur(root + 1, left, i - 1);
        node->right    = recur(i - left + root + 1, i + 1, right);
        return node;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        this->preorder = preorder;
        int idx        = 0;
        for (auto &&n : inorder) {
            dic[n] = idx++;
        }
        // 根节点，左边
        return recur(0, 0, inorder.size() - 1);
    }
};