class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> cur_vec;
        int sz = s.size();
        vector<vector<string>> res;
        if (sz == 0) {
            return res;
        }
        helper(s, 0, cur_vec, res);
        return res;
    }

private:
    void helper(string s, int pos, vector<string>& cur_vec, vector<vector<string>>& res) {
        if (pos == s.size()) {
            res.push_back(cur_vec);
            return;
        }

        //cout << "pos = " << pos << endl;
        for (int i = 1; i + pos <= s.size(); ++i) {
            string cur_str = s.substr(pos, i);
            //cout << "cur_str = " << cur_str << endl;
            if (isValid(cur_str)) {
                cur_vec.push_back(cur_str);
                helper(s, pos + i, cur_vec, res);
                cur_vec.pop_back();
            }
        }
    }

    bool isValid(string& s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }
};
