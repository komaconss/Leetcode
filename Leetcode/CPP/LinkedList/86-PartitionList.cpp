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
    ListNode* partition(ListNode* head, int x) {
        //使用两个哑结点分别连接两个链表，小于x的节点放入链表1中，大于等于x的节点放入链表2中，之后再连接起来
        if (!head) {
            return head;
        }
        ListNode dummy1(0), dummy2(0);
        ListNode* cur = head, *pre1 = &dummy1, *pre2 = &dummy2;
        while (cur) {
            if (cur->val < x) {
                pre1->next = cur;
                pre1 = pre1->next;
                //cout << "less: cur->val = " << cur->val << endl;
            } else {
                pre2->next = cur;
                pre2 = pre2->next;
                //cout << "more: cur->val = " << cur->val << endl;
            }
            cur = cur->next;
        }
        //cout << "pre1->val = " << pre1->val << endl;
        //cout << "dummy2.next->val = " << dummy2.next->val << endl;
        pre1->next = dummy2.next;
        pre2->next = nullptr;  //重点，一定要设置为nullptr，不然会变成循环链表
        cur = dummy1.next;
        while (cur) {
            //cout << "cur->val = " << cur->val << endl;
            cur = cur->next;
        }
        return dummy1.next;
    }
};
