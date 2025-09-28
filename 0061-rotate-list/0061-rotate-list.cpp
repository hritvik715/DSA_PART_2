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
    ListNode* rotateRight(ListNode* head, int k) {
          if (!head || !head->next || k == 0) return head;

        // Step 1: Find length and last node
        ListNode* last = head;
        int length = 1;
        while (last->next) {
            last = last->next;
            length++;
        }

        // Step 2: Normalize k
        k = k % length;
        if (k == 0) return head;

        // Step 3: Find new tail (length - k - 1 steps from head)
        ListNode* newTail = head;
        for (int i = 0; i < length - k - 1; ++i) {
            newTail = newTail->next;
        }

        // Step 4: New head is the next of new tail
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;  // break the list
        last->next = head;        // connect old tail to old head

        return newHead;
    }
};