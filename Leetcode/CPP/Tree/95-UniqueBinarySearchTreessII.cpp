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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};
        }

        return generate(1, n);
    }
private:
    vector<TreeNode*> generate(int left, int right) {
        if (left > right) {
            return {NULL};
        }
        vector<TreeNode*> res;
        for (int i = left; i <= right; ++i) {
            vector<TreeNode*> leftNodes = generate(left, i - 1);
            vector<TreeNode*> rightNodes = generate(i + 1, right);

            for (auto& leftNode : leftNodes) {
                for (auto& rightNode : rightNodes) {
                    TreeNode* cur = new TreeNode(i);
                    cur->left = leftNode;
                    cur->right = rightNode;
                    res.push_back(cur);
                }
            }
        }
        
        return res;
    }
};
