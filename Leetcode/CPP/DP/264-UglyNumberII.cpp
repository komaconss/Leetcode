class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n, 0);
        dp[0] = 1;
        int dp_2 = 0, dp_3 = 0, dp_5 = 0;
        for (int i = 1; i < n; ++i) {
            dp[i] = min(2 * dp[dp_2], min(3 * dp[dp_3], 5 * dp[dp_5]));
            if (dp[i] == 2 * dp[dp_2]) {
                ++dp_2;
            }
            if (dp[i] == 3 * dp[dp_3]) {
                ++dp_3;
            }
            if (dp[i] == 5 * dp[dp_5]) {
                ++dp_5;
            }
        }
        return dp[n - 1];
    }
;
