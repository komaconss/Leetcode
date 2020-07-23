class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur_vec;
        vector<vector<int>> res;
        dfs(nums, 0, cur_vec, res);
        return res;
    }
private:
    void dfs(vector<int>& nums, int pos, vector<int>& cur_vec, vector<vector<int>>& res) {
        res.push_back(cur_vec);

        for (int i = pos; i < nums.size(); ++i) {
            //加入当前元素
            cur_vec.push_back(nums[i]);
            dfs(nums, i + 1, cur_vec, res);
            cur_vec.pop_back();
        }
    }
};
