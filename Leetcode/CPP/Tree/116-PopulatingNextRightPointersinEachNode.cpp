/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        //层次遍历，每一层分别填充每个节点的next指针
        if (!root) {
            return root;
        }

        queue<Node*> que;
        que.push(root);
        while (!que.empty()) {
            int sz = que.size();
            //cout << "que.size() = " << sz << endl;
            for (int i = 0; i < sz; ++i) {
                Node* node = que.front();
                que.pop();
                //填充next指针
                if (i != sz - 1) {
                    node->next = que.front();
                } else {
                    node->next = nullptr;
                }

                if (node->left) {
                    que.push(node->left);
                }

                if (node->right) {
                    que.push(node->right);
                }
            }
        }

        return root;
    }
};
