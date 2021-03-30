/**
 * author: xmmmmmovo
 * generation time: 2021/03/30
 * filename: 剑指 Offer 18. 删除链表的节点.cpp
 * language & build version : C 11 & C++ 17
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
using ll = long long;

// Definition for singly-linked list.
struct ListNode {
    int       val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode *deleteNode(ListNode *head, int val) {
        if (head == nullptr)
            return nullptr;
        ListNode *slow = nullptr;
        ListNode *fast = head;
        while (fast != nullptr && fast->val != val) {
            slow = fast;
            fast = fast->next;
        }
        if (slow == nullptr)
            return fast->next;

        slow->next = fast->next;
        return head;
    }
};