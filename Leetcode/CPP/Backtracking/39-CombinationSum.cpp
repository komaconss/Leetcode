class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> cur_vec;
        helper(candidates, 0, target, cur_vec, res);
        return res;
    }
private:
    void helper(vector<int>& candidates, int pos, int target, vector<int>& cur_vec, vector<vector<int>>& res) {
        if (0 == target) {
            res.push_back(cur_vec);
            return;
        }

        if (target < 0) {
            return;
        }

        for (int i = pos; i < candidates.size(); ++i) {
            cur_vec.push_back(candidates[i]);
            helper(candidates, i, target - candidates[i], cur_vec, res);
            cur_vec.pop_back();
        }
    }
};
