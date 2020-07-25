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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int sz = inorder.size();
        for (int i = 0; i < sz; ++i) {
            ump[inorder[i]] = i;
        }
        return build(preorder, inorder, 0, sz - 1, 0, sz - 1);        
    }
private:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preLeft, int preRight, int inLeft, int inRight) {
        if (inLeft > inRight) {
            return NULL;
        }

        int cur_val = preorder[preLeft];
        TreeNode* cur = new TreeNode(cur_val);
        int pos = ump[cur_val];
        int num = pos - inLeft;
        cur->left = build(preorder, inorder, preLeft + 1, preLeft + num, inLeft, pos - 1);
        cur->right = build(preorder, inorder, preLeft + num + 1, preRight, pos + 1, inRight);

        return cur;
    }
private:
    unordered_map<int, int> ump;
};
