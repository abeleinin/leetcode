#include <algorithm>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
 /**
  * \c Solution
  * 
  * 1. Use fase and slow pointer
  * 2. while fast and fast->next so that you can call fast->next->next inside the loop
  * 
  * Time  : O(n)
  * Space : O(1)
  */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            if (slow == fast) {
                return true;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};