#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Node {
  public:
    int   val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
  public:
    Node *connect(Node *root) {
        if (root == nullptr)
            return root;

        root->next = nullptr;
        if(root->next == nullptr && root->right == nullptr) return root;

        stack<Node *> s;
        // calculate the number of nodes
        int fn  = 2;
        int tmp = 0;
        s.push(root->left);
        s.push(root->right);
        while (!s.empty()) {
            auto t = s.top();
            s.pop();
            s.push(t->left);
            s.push(t->right);
            if (tmp < fn) {
                t->next = s.top();
                tmp++;
                continue;
            }

            if (tmp == fn) {
                t->next = nullptr;
                tmp     = 0;
                fn *= 2;
                continue;
            }

            tmp++;
        }

        return root;
    }
};