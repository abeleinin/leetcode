#!/usr/bin/python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: list) -> bool:
        if head == None or head.next == None:
            return False
        slow = head.next
        fast = head.next.next
        while fast != None or slow != None:
            if fast == slow:
                return True
            if slow.next == None or fast.next == None or fast.next.next == None:
                return False
            else:
                slow = slow.next
                fast = fast.next.next
        return False
