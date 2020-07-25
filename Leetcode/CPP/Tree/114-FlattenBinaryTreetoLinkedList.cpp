/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        //后序遍历展开
        //将左子树插入到右子树的地方
        //将原来的右子树接到左子树的最右边节点
        //考虑新的右子树的根节点，一直重复上边的过程，直到新的右子树为 null
        if (!root) {
            return;
        }

        while (root) {
            TreeNode* tmp = root->left;
            if (tmp) {
                while (tmp->right) {
                    tmp = tmp->right;
                }
                tmp->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }  
            root = root->right;         
        }
    }
};
