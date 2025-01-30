#include <algorithm>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
/**
 * \c Solution
 * 
 * 1. Temporarily store teh next node (curr->next)
 * 2. Set curr->next to previous
 * 3. Set previous to the current node
 * 4. Set current to the temporary node (next)
 * 
 * Time  : O(n)
 * Space : O(n)
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};