from typing import Optional

# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        dummy = Node(0)
        copy = dummy
        curr = head
        h = {}
        while curr:
            new = Node(curr.val)
            h[curr] = new
            copy.next = new
            curr = curr.next
            copy = copy.next
        
        curr = head
        copy = dummy
        while curr:
            if curr.random in h:
                random_node = h[curr.random]
            else: 
                random_node = None
            copy.next.random = random_node
            curr = curr.next
            copy = copy.next
            
        return dummy.next;        