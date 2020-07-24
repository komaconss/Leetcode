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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) {
            return res;
        }

        deque<TreeNode*> que;
        que.push_back(root);
        bool flag = true;
        while (!que.empty()) {
            int level = que.size();
            //cout << "level = " << level << endl;
            vector<int> tmp;
            for (int i = 0; i < level; ++i) {
                TreeNode* cur = que.front();
                tmp.push_back(cur->val);
                que.pop_front();
                if (cur->left) {
                    que.push_back(cur->left);
                }
                if (cur->right) {
                    que.push_back(cur->right);
                }
            }
            if (!flag) {
                reverse(tmp.begin(), tmp.end());
            }
            res.push_back(tmp);
            flag = !flag;
        }
        return res;
    }

private:
    vector<vector<int>> res;
};
