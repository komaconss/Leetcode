class Solution {
public:
    int uniquePaths(int m, int n) {
        int res = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = 1;
        //1.处理第一行
        for (int i = 1; i < n; ++i) {
            dp[0][i] = dp[0][i - 1];
        }

        //2.处理第一列
        for (int i = 1; i < m; ++i) {
            dp[i][0] = dp[i - 1][0];
        }

        //3.处理其他位置
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};
