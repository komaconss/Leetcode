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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode* cur = head;
        ListNode* pre = &dummy;

        while (cur) {
            if ((cur->next) && (cur->next->val < cur->val)) {
                while ((pre->next) && (pre->next->val < cur->next->val)) {
                    pre = pre->next; //从链表头部开始找到第一个大于等于当前结点的结点的前驱结点
                }
                //cout << "cur->val " << cur->val << ", pre->val = " << pre->val << endl;
                ListNode* tmp = pre->next;//要插入节点位置的后继结点
                pre->next = cur->next;
                cur->next = cur->next->next;                
                pre->next->next = tmp;
                pre = &dummy;
            } else {
                cur = cur->next;
            }            
        }

        return dummy.next;
    }
};
