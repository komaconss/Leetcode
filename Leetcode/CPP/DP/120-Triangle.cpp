class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //动态规划的题型，从底向上遍历
        //状态转移方程：dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];

        int rows = triangle.size();
        if (rows == 0) {
            return 0;
        }
        int cols = triangle[rows - 1].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        //1.初始化最后一行
        for (int i = 0; i < cols; ++i) {
            dp[rows - 1][i] = triangle[rows - 1][i];
        }

        /*for (const auto& e : dp) {
            for (const auto& elem : e) {
                cout << elem << " ";
            }
            cout << endl;
        }*/
        //2.更新其他位置的值
        for (int i = rows - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
            }
        }

        return dp[0][0];
    }
};
