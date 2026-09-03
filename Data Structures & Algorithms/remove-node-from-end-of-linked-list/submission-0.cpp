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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head); // Dummy node before head
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;

        // Move fast n + 1 steps ahead to keep a gap of n
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move both pointers until fast reaches the end
        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }

        // Now slow->next is the node to delete
        slow->next = slow->next->next;

        return dummy.next; // Return new head
    }
};
