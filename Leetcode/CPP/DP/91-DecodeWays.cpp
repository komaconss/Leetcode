class Solution {
public:
    int numDecodings(string s) {
        //需要用动态规划的方法
        //dp[i]表示以s[i]结尾的子串有多少种解码方式
        //状态转义方程：
        //1.dp[0] = 1;
        //2.dp[i] 分三种情况讨论
        //2.1 s[i] = '0', 如果s[i - 1]不等于'1'或'2'，则return 0，不然dp[i] = dp[i - 2];
        //2.2 s[i - 1] = '1', dp[i] = dp[i - 1] + dp[i - 2];
        //2.3 s[i - 2] = '2', 如果s[i]等于1到6之间的数，则dp[i] = dp[i - 2] + dp[i - 1], 否则dp[i] = dp[i - 1];
        int sz = s.size();
        if (sz == 0 || s[0] == '0') {
            return 0;
        }
        int pre = 1, cur = 1;
        for (int i = 1; i < sz; ++i) {
            int tmp = cur;
            if (s[i] == '0') {
                if (s[i - 1] == '1' || s[i - 1] == '2') {
                    cur = pre;
                } else {
                    return 0;
                }
            } else if (s[i - 1] == '1' || (s[i - 1] == '2' && (s[i] >= '1' && s[i] <= '6'))) {
                cur = pre + cur;
            }
            pre = tmp;
        }
        return cur;
    }
};
