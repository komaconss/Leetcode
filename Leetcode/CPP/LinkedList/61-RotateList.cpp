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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) {
            return head;
        }

        ListNode* cur = head;
        int len = 1;
        while (cur->next) {
            cur = cur->next;
            ++len;
        }

        if (k % len == 0) {
            return head;
        }

        cur->next = head;
        int m = len - k%len;
        while (m > 0) {
            --m;
            cur = cur->next;
        }
        //目前cur是新链表的尾结点
        head = cur->next;
        cur->next = nullptr;
        return head;
    }
};
