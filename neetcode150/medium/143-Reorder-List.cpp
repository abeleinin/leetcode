#include <algorithm>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse fast
        ListNode* curr = slow->next;
        ListNode* nxt = NULL;
        ListNode* prev = NULL;
        while (curr != NULL) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        slow->next = NULL;

        // Merge
        ListNode* first = head; 
        ListNode* second = prev; 

        while (second != NULL) {
            ListNode* first_nxt = first->next;
            ListNode* second_nxt = second->next;

            first->next = second;
            second->next = first_nxt;
            first = first_nxt;
            second = second_nxt;
        }
    }
};