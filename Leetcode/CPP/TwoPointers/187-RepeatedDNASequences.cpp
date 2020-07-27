class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        //使用滑动窗口的方式来寻找结果
        vector<string> res;
        int sz = s.size();
        if (sz == 0) {
            return res;
        }
        int L = 10;
        unordered_map<string, int> ump;
        for (int i = 0; i <= sz - L; ++i) {
            string str = s.substr(i, L);
            ++ump[str];
        }
        for (auto& item : ump) {
            if (item.second > 1) {
                res.push_back(item.first);
            }
        }
        return res;
    }
};
