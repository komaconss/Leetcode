/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode dummy(0);
        dummy.next = head;

        ListNode* pre = &dummy;
        ListNode* cur = head;
        ListNode* next = cur->next;

        while (cur && next) {
            pre->next = next;
            cur->next = next->next;
            next->next = cur;

            pre = cur;
            cur = cur->next;
            if (cur) {
                next = cur->next;
            }
        }

        return dummy.next;
    }
};
