/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        //1.通过快慢指针寻找中间结点
        //2.构建二叉搜索树
        if (head == nullptr) {
            return nullptr;
        }

        ListNode* mid = findMidNode(head);

        TreeNode* cur = new TreeNode(mid->val);
        if (head == mid) {
            return cur;
        }
        
        cur->left = sortedListToBST(head);
        cur->right = sortedListToBST(mid->next);

        return cur;
    }

private:
    ListNode* findMidNode(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* pre = nullptr;
        ListNode* fast = head, *slow = head;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        } 

        if (pre) {//断开链表
            pre->next = nullptr;
        }

        return slow;
    }
};
