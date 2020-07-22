class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //采用滑动窗口的方式
        //[i, j] 表示当前索引值为i和j范围内的子串是不重复的
        //需要用一个map来记录非重复元素的字符和索引
        int sz = s.size();
        if (sz == 0) {
            return 0;
        }
        unordered_set<char> st;
        int left = 0;
        int res = 0;
        for (int i = 0; i < sz; ++i) {
            while (st.find(s[i]) != st.end()) {
                st.erase(s[left]);
                ++left;
            }
            st.insert(s[i]);
            int curSum = i - left + 1;
            res = max(res, curSum);
        }
        return res;
    }
};
