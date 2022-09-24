#!/usr/bin/python3
# Definition for singly-linked list.
# class ListNode:
#   def __init__(self, val=0, next=None):
#     self.val = val
#     self.next = next
class Solution:
  # Optimal Solution
  def reverseList(self, head: list) -> list:
    curr = head
    prev = None
    while curr != None:
      nxt = curr.next
      curr.next = prev
      prev = curr
      curr = nxt
    return prev