class Solution {
public:
    string convert(string s, int numRows) {
        int sz = s.size();
        if (numRows == 1) {
            return s;
        }
        vector<string> vec(numRows);
        bool goDown = false;
        int row = 0;
        for (int i = 0; i < sz; ++i) {
            vec[row] += s[i];
            if (row == 0 || row == numRows - 1) {
                goDown = !goDown;
            }
            row += goDown ? 1 : -1;
        }
        string res;
        for (auto& str : vec) {
            res += str;
        }
        return res;
    }
};
