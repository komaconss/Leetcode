class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> ust;
        for (auto& num : wordDict) {
            ust.insert(num);
        }

        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && ust.find(s.substr(j, i - j)) != ust.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
