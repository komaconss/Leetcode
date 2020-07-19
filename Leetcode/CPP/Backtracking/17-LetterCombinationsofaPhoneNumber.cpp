class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return res;
        }
        DFS(digits, 0);
        return res;
    }
private:
    void DFS(const string& digits, int num) {
        if (num == digits.size()) {
            res.push_back(cur_str);
            return;
        }
        for (int i = 0; i < mp[digits[num]].size(); ++i) {
            cur_str.push_back(mp[digits[num]][i]);
            DFS(digits, num + 1);
            cur_str.pop_back();
        }
    }

private:
    unordered_map<char, string> mp = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
                                      {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    vector<string> res;
    string cur_str;
};
