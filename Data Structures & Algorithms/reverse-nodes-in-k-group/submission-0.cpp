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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return nullptr;
        ListNode* a = head;
        ListNode* b = head;
        for (int i = 0; i < k; i++) {
            if (!b) return head; // not enough nodes
            b = b->next;
        }

        // reverse [a, b)
        ListNode* newHead = reverse(a, b);
        a->next = reverseKGroup(b, k);
        return newHead;
    }

    ListNode* reverse(ListNode* a, ListNode* b) {
        ListNode* prev = nullptr;
        ListNode* curr = a;
        while (curr != b) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
