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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head) {
            return head;
        }

        if (m == 1) {
            ListNode* res = reverseN(head, n);
            return res;
        }
        //不断递归，直到找到开始翻转的位置
        head->next = reverseBetween(head->next, m - 1, n - 1);
        return head;
    }
private:
    //前n个元素翻转
    ListNode* reverseN(ListNode* head, int n) {
        if (n == 1) {
            successor = head->next;
            return head;
        }

        if (!head || !head->next) {
            return head;
        }

        ListNode* newHead = reverseN(head->next, n - 1);
        head->next->next = head;
        head->next = successor;

        return newHead;
    }
private:
    ListNode* successor = NULL;
};
