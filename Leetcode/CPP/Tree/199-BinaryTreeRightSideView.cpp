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
    vector<int> rightSideView(TreeNode* root) {
        //层次遍历，每次保留最后一个元素
        vector<int> res;
        if (!root) {
            return res;
        }
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int sz = que.size();
            for (int i = 0; i < sz; ++i) {
                TreeNode* cur = que.front();
                que.pop();
                if (cur->left) {
                    que.push(cur->left);
                }
                if (cur->right) {
                    que.push(cur->right);
                }
                if (i == sz - 1) {
                    res.push_back(cur->val);
                }
            }            
        }
        return res;
    }
};
