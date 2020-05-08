#
# @lc app=leetcode.cn id=445 lang=python3
#
# [445] 两数相加 II
#


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


# @lc code=start

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        r1, r2 = [], []

        while l1:
            r1.append(l1.val)
            l1 = l1.next

        while l2:
            r2.append(l2.val)
            l2 = l2.next

        head = None
        c, s = 0, 0
        while r1 or r2 or c != 0:
            v1, v2 = 0, 0
            if r1:
                v1 = r1.pop()
            if r2:
                v2 = r2.pop()
            s = v1 + v2 + c
            c = s // 10
            cn = ListNode(s % 10)
            cn.next = head
            head = cn
        return head

# @lc code=end
