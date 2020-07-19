class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int sz = nums.size();
        if (sz < 0) {
            return res;
        }
        sort(nums.begin(), nums.end());

        for (int i = 0; i < sz; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1, right = sz - 1;
            int target = -nums[i];
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum == target) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    ++left;
                    --right;
                    while (left < right && nums[left] == nums[left - 1]) {
                        ++left;
                    }
                    while (left < right && nums[right] == nums[right + 1]) {
                        --right;
                    }
                }                
                if (sum > target) {
                    --right;
                }
                if (sum < target) {
                    ++left;
                }
            }
        }
        return res;
    }
};
