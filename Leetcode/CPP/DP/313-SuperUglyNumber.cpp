class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int sz = primes.size();
        if (sz == 0) {
            return 1;
        }
        int res = 1;
        vector<int> dp(n, 1);
        vector<int> tmp(sz);
        for (int i = 1; i < n; ++i) {
            int minVal = INT_MAX;
            for (int j = 0; j < sz; ++j) {
                minVal = min(minVal, primes[j] * dp[tmp[j]]);
            }
            dp[i] = minVal;
            for (int j = 0; j < sz; ++j) {
                if (minVal == primes[j] * dp[tmp[j]]) {
                    ++tmp[j];
                }
            }
        }
        return dp[n - 1];
    }
};
