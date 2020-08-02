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
    int rob(TreeNode* root) {
        vector<int> dp(2, 0);
        dp = helper(root);
        return max(dp[0], dp[1]);
    }
private:
    vector<int> helper(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }
        vector<int> tmp(2, 0);
        auto left = helper(root->left);
        auto right = helper(root->right);
        //根节点不抢，其他节点取抢或不抢的最大值
        tmp[0] = max(left[0], left[1]) + max(right[0], right[1]);
        //根节点抢
        tmp[1] = left[0] + right[0] + root->val;
        return tmp;
    }
};
