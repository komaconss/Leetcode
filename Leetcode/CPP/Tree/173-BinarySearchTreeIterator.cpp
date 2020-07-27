/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    /** @return the next smallest number */
    int next() {
        return nums[pos++];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return pos < nums.size();
    }

private:
    vector<int> nums;
    int pos = 0;

private:
    void inorder(TreeNode* root) {
        if (!root) {
            return;
        }
        inorder(root->left);
        nums.push_back(root->val);
        inorder(root->right);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
