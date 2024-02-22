from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)
        res = dummy
        carry = 0
        while l1 or l2 or carry == 1:
            if l1 and l2:
                t = l1.val + l2.val + carry
                l1 = l1.next
                l2 = l2.next
            elif l1 and not l2:
                t = l1.val + carry
                l1 = l1.next
            elif l2 and not l1:
                t = l2.val + carry
                l2 = l2.next
            else:
                t = carry
            carry = 0
            if t >= 10:
                t = t % 10
                carry = 1
            res.next = ListNode(t)
            res = res.next
        return dummy.next