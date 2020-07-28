class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        //动态规划
        //dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1
        //dp[i][j] = 1, if i == 0 || j == 0

        int rows = matrix.size();
        if (rows == 0) {
            return 0;
        }
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        int res = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                    }                    
                    //cout << "dp[i][j] = " << dp[i][j] << endl;
                    res = max(res, dp[i][j]);
                } 
            }
        }
        return res * res;
    }
};
