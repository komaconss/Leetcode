class Solution {
public:
    int rob(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0) {
            return 0;
        }
        if (sz == 1) {
            return nums[0];
        }

        return max(helper(nums, 0, sz - 2), helper(nums, 1, sz - 1));
    }
private:
    int helper(vector<int>& nums, int start, int end) {
        int dp_i_1 = 0, dp_i_2 = 0;
        int dp_i_0 = 0;
        for (int i = start; i <= end; ++i) {
            dp_i_0 = max(dp_i_1, nums[i] + dp_i_2);
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i_0;
        }
        return dp_i_0;
    }
};
