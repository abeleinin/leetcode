#!/usr/bin/python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
  def mergeTwoLists(self, list1: list, list2: list) -> list:
    # Base cases 
    if list1 == None:
      return list2
    if list2 == None:
      return list1
    
    # Determine which node is the smaller and recursively build the 
    # rest of the list
    if list1.val < list2.val:
      list1.next = self.mergeTwoLists(list1.next, list2)
      return list1
    else:
      list2.next = self.mergeTwoLists(list2.next, list1)
      return list2
