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
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        TreeNode* lt = root;
        TreeNode* rt = root;
        int left = 0, right = 0;
        while (lt) {
            lt = lt->left;
            ++left;
        }
        while (rt) {
            rt = rt->right;
            ++right;
        }
        if (left == right) {
            return pow(2, left) - 1;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
