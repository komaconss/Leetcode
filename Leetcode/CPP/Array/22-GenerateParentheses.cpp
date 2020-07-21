class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str;
        helper(res, str, 0, 0, n);
        return res;
    }
private:
    void helper(vector<string>& res, string& str, int left, int right, int n) {
        if (left == n && right == n) {
            res.push_back(str);
            return;
        }

        if (left < n) {
            str.push_back('(');
            helper(res, str, left + 1, right, n);
            str.pop_back();
        }
        
        if (right < left) {
            str.push_back(')');
            helper(res, str, left, right + 1, n);
            str.pop_back();
        }        
    }
};
