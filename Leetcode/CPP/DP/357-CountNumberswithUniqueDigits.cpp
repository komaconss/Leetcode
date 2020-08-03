class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp(n, 0);
        if (n == 0) {
            return 1;
        }
        int tmp = 9;
        dp[0] = 10;
        for (int i = 1; i < n; ++i) {
            tmp = tmp * (9 - i + 1);
            dp[i] = dp[i - 1] + tmp;
        }
        return dp[n - 1];
    }
};
