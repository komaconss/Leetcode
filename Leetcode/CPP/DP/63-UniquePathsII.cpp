class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int res = 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        //cout << "m = " << m << ", n = " << n << endl;
        if (m == 0 || n == 0) {
            return 0;
        }
        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = obstacleGrid[0][0] == 0 ? 1 : 0;
        //1.处理第一行
        for (int i = 1; i < n; ++i) {
            dp[0][i] = obstacleGrid[0][i] == 0 ? dp[0][i - 1] : 0;
        }

        //2.处理第一列
        for (int i = 1; i < m; ++i) {
            dp[i][0] = obstacleGrid[i][0] == 0 ? dp[i - 1][0] : 0;
        }

        //3.处理其他位置
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }                
            }
        }

        return dp[m - 1][n - 1];
    }
};
