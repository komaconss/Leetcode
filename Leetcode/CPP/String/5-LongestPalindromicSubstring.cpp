class Solution {
public:
    string longestPalindrome(string s) {
        int sz = s.size();
        if (sz < 2) {
            return s;
        }

        vector<vector<int>> dp(sz, vector<int>(sz, 1));
        int maxLen = 1;
        int beg = 0;
        for (int j = 1; j < sz; ++j) {
            for (int i = 0; i < j; ++i) { //注意只需要遍历对角线上面的值
                if (s[i] != s[j]) {
                    dp[i][j] = 0;
                } else {
                    if (j - i < 3) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                if (dp[i][j] == 1 && (j - i + 1) > maxLen) {
                    maxLen = j - i + 1;
                    beg = i;
                }
            }    
        }
        return s.substr(beg, maxLen);
    }
};
