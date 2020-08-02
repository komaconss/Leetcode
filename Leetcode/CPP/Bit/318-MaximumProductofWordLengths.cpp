class Solution {
public:
    int maxProduct(vector<string>& words) {
        int sz = words.size();
        vector<int> tmp(sz, 0);
        //1.预处理words数组，将其中的值转为int
        for (int i = 0; i < sz; ++i) {
            tmp[i] = string2Int(words[i]);
        }
        int res = 0;
        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < i; ++j) {
                if ((tmp[i] & tmp[j]) == 0 && (words[i].size() * words[j].size() > res)) {
                    res = words[i].size() * words[j].size();
                }
            }
        }
        return res;
    }
private:
    int string2Int(string& str) {
        int val = 0;
        for (auto& c : str) {
            val |= 1 << (c - 'a');
        }
        return val;
    }
};
