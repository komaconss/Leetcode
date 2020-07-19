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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* node = new ListNode(0);
        node->next = head;
        ListNode* cur = node;
        while (head && n > 0) {
            head = head->next;
            --n;
        }
        while (head) {
            head = head->next;
            cur = cur->next;
        }
        cur->next = cur->next->next;
        return node->next;
    }
};
