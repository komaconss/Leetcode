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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int sz = inorder.size();
        for (int i = 0; i < sz; ++i) {
            ump[inorder[i]] = i;
        }
        return build(postorder, inorder, 0, sz - 1, 0, sz - 1);        
    }
private:
    TreeNode* build(vector<int>& postorder, vector<int>& inorder, int postLeft, int postRight, int inLeft, int inRight) {
        if (inLeft > inRight) {
            return NULL;
        }

        int cur_val = postorder[postRight];
        TreeNode* cur = new TreeNode(cur_val);
        int pos = ump[cur_val];
        int num = pos - inLeft;
        cur->left = build(postorder, inorder, postLeft, postLeft + num - 1, inLeft, pos - 1);
        cur->right = build(postorder, inorder, postLeft + num, postRight - 1, pos + 1, inRight);

        return cur;
    }
private:
    unordered_map<int, int> ump;
};
