class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int sz = nums.size();
        vector<long> dp(target + 1, 0);
        for (int i = 0; i < sz; ++i) {
            if (nums[i] <= target) {
                dp[nums[i]] = 1;
            }            
        }
        for (int i = 1; i <= target; ++i) {
            for (int j = 0; j < sz; ++j) {
                if (i - nums[j] >= 0) {
                    dp[i] = dp[i] >= INT_MAX - dp[i - nums[j]] ? INT_MAX : dp[i] + dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }
};
