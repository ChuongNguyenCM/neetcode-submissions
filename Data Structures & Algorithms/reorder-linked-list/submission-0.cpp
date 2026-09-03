/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // Step 1: Find the middle (slow will point to middle)
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* second = slow->next;
        slow->next = nullptr; // cut the list
        ListNode* prev = nullptr;
        while (second) {
            ListNode* tmp = second->next;
            second->next = prev;
            prev = second;
            second = tmp;
        }

        // Step 3: Merge two halves
        ListNode* first = head;
        ListNode* l2 = prev;
        while (first && l2) {
            ListNode* n1 = first->next;
            ListNode* n2 = l2->next;

            first->next = l2;
            if (n1 == nullptr) break;
            l2->next = n1;

            first = n1;
            l2 = n2;
        }
    }
};
