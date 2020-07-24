class Solution {
public:
    int numTrees(int n) {
        //1.动态规划的方式计算
        //dp[i] = sigma dp[i - 1] * dp[n - i];
        //2.卡特兰数计算公式
        vector<int> dp(n + 1, 0);
        dp[0] = 1, dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        /*for (auto& e : dp) {
            cout << e << " ";
        }
        cout << endl;*/
        return dp[n];
    }
};
