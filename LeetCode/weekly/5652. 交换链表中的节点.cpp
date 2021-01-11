#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int       val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
  public:
    ListNode *swapNodes(ListNode *head, int k) {
        if (head == nullptr)
            return nullptr;
        ListNode *l = head;

        while (k-- > 1) {
            l = l->next;
        }

        ListNode *slow = head, *fast = l;
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        swap(slow->val, l->val);

        return head;
    }
};