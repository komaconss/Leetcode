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
    vector<int> preorderTraversal(TreeNode* root) {
         vector<int> res;
         if (!root) {
             return res;
         }

         stack<TreeNode*> st;
         st.push(root);
         while (!st.empty()) {
             TreeNode* cur = st.top();
             st.pop();
             res.push_back(cur->val);

             if (cur->right) {
                 st.push(cur->right);
             }

             if (cur->left) {
                 st.push(cur->left);
             }
         }

         return res;
    }
};
