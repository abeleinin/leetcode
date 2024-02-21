from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        slow = head
        fast = head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        # reverse fast
        nxt, prev = None, None
        curr = slow.next
        slow.next = None
        while curr != None:
            nxt = curr.next
            curr.next = prev 
            prev = curr
            curr = nxt
        
        # merge head and prev
        first, second = head, prev

        while second:
            first_nxt = first.next
            second_nxt = second.next

            first.next = second
            second.next = first_nxt
            first = first_nxt
            second = second_nxt