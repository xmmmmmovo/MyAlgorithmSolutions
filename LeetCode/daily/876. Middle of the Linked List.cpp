struct ListNode {
    int       val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *middleNode(ListNode *head) {
        auto *s = head;
        auto  f = s;
        while (f != nullptr && f->next != nullptr) {
            s = s->next;
            f = f->next->next;
        }
        return s;
    }
};