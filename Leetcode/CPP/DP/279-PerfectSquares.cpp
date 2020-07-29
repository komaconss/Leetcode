class Solution {
public:
    int numSquares(int n) {
        //使用动态规划的方法
        //dp[i]表示和等于n组成和的完全平方数的个数最少个数
        vector<int> dp(n + 1, n);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                dp[i] = min(dp[i - j * j] + 1, dp[i]);
            }
        }
        return dp[n];
    }
};
