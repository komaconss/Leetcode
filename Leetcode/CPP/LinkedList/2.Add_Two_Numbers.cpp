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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       if(!l1)
        return l2;
       if(!l2)
        return l1;
       int carry = 0;
       int sum = 0;
       ListNode *res = l1;
       while(true)
       {
          sum = l1 -> val + l2 -> val + carry;
          if(sum > 9){ //进位判断
             carry = 1;
             sum -= 10;
          }
          else{
              carry = 0;
          }
           l1 -> val = sum;
          if(l1 -> next == nullptr)//剩余元素的处理
          {
              l1 -> next = l2 -> next;
              break;
          }
          else if(l2 -> next == nullptr)
          {
              break;
          }
          l1 = l1 -> next;
          l2 = l2 -> next;
       }
       while(l1 -> next != nullptr && carry)
       {
           l1 = l1 -> next;
           sum = l1 -> val + carry;
           if(sum > 9){
             carry = 1;
             sum -= 10;
          }
          else{
              carry = 0;
          }
           l1 -> val = sum;
           
       }
       if(carry)//最后还有进位的情况，需要再创建一个结点
       {
           ListNode *tmp = new ListNode(carry);
           l1 -> next = tmp;
       }
       
       return res;
    }
        
};

//更简洁的解法：
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode preHead(0), *p = &preHead;
    int extra = 0;
    while (l1 || l2 || extra) {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
        extra = sum / 10;
        p->next = new ListNode(sum % 10);
        p = p->next;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
    return preHead.next;
}
