class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur_vec;
        sort(candidates.begin(), candidates.end());
        helper(candidates, 0, target, cur_vec, res);

        return res;
    }
private:
    void helper(vector<int>& candidates, int pos, int target, vector<int>& cur_vec, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(cur_vec);
            return;
        }

        if (pos == candidates.size() || target < 0) {
            return;
        }

        for (int i = pos; i < candidates.size(); ++i) {
	    //对重复元素的判断
            if (i > pos && candidates[i] == candidates[i - 1]) {
                continue;
            }
            cur_vec.push_back(candidates[i]);
            helper(candidates, i + 1, target - candidates[i], cur_vec, res);
            cur_vec.pop_back();
        }
    }
};
