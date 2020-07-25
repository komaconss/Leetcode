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
    int sumNumbers(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        return helper(root, 0);
    }

private:
    int helper(TreeNode* root, int cur_sum) {
        if (root == nullptr) {
            return 0;
        }
        
        cur_sum = cur_sum * 10 + root->val;

        if (!root->left && !root->right) {
            return cur_sum;
        }

        //cout << "cur_sum = " << cur_sum << endl;

        return helper(root->left, cur_sum) + helper(root->right, cur_sum);
    }
};
