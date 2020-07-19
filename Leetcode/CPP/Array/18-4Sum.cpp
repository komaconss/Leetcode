class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int sz = nums.size();
        if (sz < 4) {
            return res;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < sz - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < sz - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int left = j + 1, right = sz - 1;
                //cout << "i = " << i << ", j = " << j << ", left = " << left << ", right = " << right << endl;
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        ++left;
                        --right;
                        while (left < right && nums[left] == nums[left - 1]) {
                            ++left;
                        }
                        while (left < right && nums[right] == nums[right + 1]) {
                            --right;
                        }
                    }
                    if (sum < target) {
                        ++left;
                    }
                    if (sum > target) {
                        --right;
                    }                    
                }
            }
        }
        return res;
    }
};
