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
    ListNode* deleteDuplicates(ListNode* head) {
        //通过哑结点来处理头结点，从而可以统一处理所有的结点
        if (!head) {
            return head;
        }
        ListNode dummy(0);
        dummy.next = head;

        ListNode* cur = head, *pre = &dummy;
        int val = head->val;
        int count = 1;

        while (cur->next){
            ListNode* next = cur->next;
            if (next->val == val) {
                ++count;
            } else {
                if (count > 1) {
                    //cout << "repeated: cur->val = " << cur->val << ", pre->val = " << pre->val << ", next->val = " << next->val << endl;
                    pre->next = next;
                } else {
                    //cout << "unique: cur->val = " << cur->val << ", pre->val = " << pre->val << ", next->val = " << next->val << endl;
                    pre = cur;
                }
                count = 1;
                val = next->val;
            }
            cur = cur->next;
        }
        if (count > 1) {
            pre->next = cur->next;
        }
        return dummy.next;
    }
};
