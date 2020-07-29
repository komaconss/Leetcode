class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //动态规划的方法
        //dp[i][0]表示第i天未持有股票
        //dp[i][1]表示第i天持有股票
        //状态方程更新方式：
        //1.昨天未持有,今天也未持有 dp[i - 1][0]
        //2.昨天持有，今天卖出 dp[i - 1][1] + prices[i  - 1]
        //dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i - 1])
        //1.昨天持有，今天不动，依旧持有
        //2.昨天未持有，看前天的收益状态
        //dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i - 1])
        int sz = prices.size();
        if (sz <= 1) {
            return 0;
        }
        vector<vector<int>> dp(sz + 1, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[1][0] = 0;
        dp[1][1] = -prices[0];
        int res = 0;
        for (int i = 2; i <= sz; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i - 1]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i - 1]);
        }
        return dp[sz][0];
    }
};
