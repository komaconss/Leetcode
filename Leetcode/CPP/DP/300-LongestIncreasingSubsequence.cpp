class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //动态规划的方法
        //dp[i]表示以第i个元素结尾的最长子序列的长度
        int sz = nums.size();
        if (0 == sz) {
            return 0;
        }
        vector<int> dp(sz, 1);
        int res = 1;
        for (int i = 1; i < sz; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
