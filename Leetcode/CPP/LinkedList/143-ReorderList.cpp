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
    void reorderList(ListNode* head) {
        //思路：找到链表中点，翻转后半部分，依次插入节点
        if (!head || !head->next) {
            return;
        }
        
        ListNode *fast = head, *slow = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        //后半段的头结点
        ListNode* newHead = slow->next;
        slow->next = nullptr;

        //将后半段反转
        newHead = reverse_list(newHead);

        //将后半段插入到前半段中
        while (newHead) {
            ListNode* next = head->next;
            ListNode* next2 = newHead->next;
            head->next = newHead;
            newHead->next = next;
            head = next;
            newHead = next2;
        } 
    }

private:
    ListNode* reverse_list(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* newHead = reverse_list(head->next);
        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }
};
