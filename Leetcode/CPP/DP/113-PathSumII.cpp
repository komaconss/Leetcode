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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> cur_vec;
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        cur_vec.push_back(root->val);
        helper(root, sum, root->val, cur_vec, res);
        return res;
    }

private:
    void helper(TreeNode* root, int sum, int cur_sum, vector<int>& cur_vec, vector<vector<int>>& res) {
        if (root == nullptr) {
            return;
        }
        
        //cout << "cur_sum = " << cur_sum << endl;
        if (cur_sum == sum && root->left == nullptr && root->right == nullptr) {
            //遍历到叶子节点且路径总和等于sum，表示找到符合要求的路径
            res.push_back(cur_vec);
            return;
        }

        if (root->left) {
            cur_vec.push_back(root->left->val);
            helper(root->left, sum, cur_sum + root->left->val, cur_vec, res);
            cur_vec.pop_back();
        }

        if (root->right) {
            cur_vec.push_back(root->right->val);
            helper(root->right, sum, cur_sum + root->right->val, cur_vec, res);
            cur_vec.pop_back();
        }
    }
};
