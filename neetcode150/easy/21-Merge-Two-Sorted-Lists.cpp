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
 * \c Solution1
 * 
 * Recursive
 * 
 * Time  : O(n+m)
 * Space : O(n+m)
 */
class Solution1 {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }
        if (list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};

/**
 * \c Solution2
 * 
 * Iterative
 * 
 * Time  : O(n+m)
 * Space : O(1)
 */
class Solution2 {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        } else if (list2 == nullptr) {
            return list1;
        }

        ListNode* curr = list1;
        if (list1->val > list2->val) {
            curr = list2;
            list2 = list2->next;
        } else {
            list1 = list1->next;
        }
        ListNode* ptr = curr;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

        if (list1 == nullptr) {
            curr->next = list2;
        } else {
            curr->next = list1;
        }
        return ptr;
    }
};