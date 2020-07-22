class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        vector<int> cur_vec;
        dfs(nums, 0, used, cur_vec, res);

        return res;
    }
private:
    void dfs(vector<int>& nums, int pos, vector<bool>& used, vector<int>& cur_vec, vector<vector<int>>& res) {
        if (cur_vec.size() == nums.size()) {
            res.push_back(cur_vec);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            //判断是否重复
            if (used[i] || (i > 0 && used[i - 1] && nums[i] == nums[i - 1])) {
                continue;
            }
            used[i] = true;
            cur_vec.push_back(nums[i]);
            dfs(nums, pos + 1, used, cur_vec, res);
            cur_vec.pop_back();
            used[i] = false;
        }
    }    
};
