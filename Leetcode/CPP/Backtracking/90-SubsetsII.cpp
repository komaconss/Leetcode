class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        int sz = nums.size();
        if (sz == 0) {
            return res;
        }
        sort(nums.begin(), nums.end());
        vector<int> cur_vec;
        dfs(nums, 0, cur_vec, res);

        return res;
    }

private:
    void dfs(vector<int>& nums, int pos, vector<int>& cur_vec, vector<vector<int>>& res) {
        res.push_back(cur_vec);//子集问题的特点，先加入当前的数组

        /*cout << "pos = " << pos << endl;
        for (const auto& e : cur_vec) {
            cout << e << " ";
        }
        cout << endl;*/

        for (int i = pos; i < nums.size(); ++i) {
            if (i > pos && nums[i] == nums[i - 1]) {
                //在同一层判断是否是重复元素，避免生成重复的子集
                //cout << "skip" << endl;
                continue;
            }
            cur_vec.push_back(nums[i]);
            dfs(nums, i + 1, cur_vec, res);
            cur_vec.pop_back();
        }
    }
};
