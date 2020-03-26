#
# @lc app=leetcode.cn id=876 lang=python3
#
# [876] 链表的中间结点
#

# Definition for singly-linked list.
from pprint import pprint


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

# @lc code=start


class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        tmp = head
        cnt = 0
        while tmp:
            cnt += 1
            tmp = tmp.next

        cnt = cnt // 2

        while cnt:
            head = head.next
            cnt -= 1

        return head


class Solution2:
    def middleNode(self, head: ListNode) -> ListNode:
        ans = []

        while head:
            ans.append(head)
            head = head.next

        return ans[len(ans)//2]


class Solution3:
    def middleNode(self, head: ListNode) -> ListNode:
        """
        快慢指针法
        快的一次两格 慢的一次一格
        然后就是快指针到最后慢指针就会刚好到中间
        """
        slow = fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        return slow

# @lc code=end
