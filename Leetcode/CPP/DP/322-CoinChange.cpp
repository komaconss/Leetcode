class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int sz = coins.size();
        if (sz == 0) {
            return 0;
        }
        vector<int> dp(amount + 1, amount + 1);
        //dp[i]表示总金额为i时最少需要的硬币数
        //dp[i] = min(dp[i - coins[i]], dp[i - coins[i - 1]],...) + 1
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < sz; ++j) {
                if (i - coins[j] >= 0) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
