class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> cur_vec;
        helper(k, n, 1, cur_vec, res);
        return res;
    }
private:
    void helper(int k, int n, int num, vector<int>& cur_vec, vector<vector<int>>& res) {
        if (k == 0 && n == 0) {
            res.push_back(cur_vec);
            return;
        }
        if (k == 0 || n == 0) {
            return;
        }

        for (int i = num; i <= 9; ++i) {
            cur_vec.push_back(i);
            helper(k - 1, n - i, i + 1, cur_vec, res);
            cur_vec.pop_back();
        }
    }
};
