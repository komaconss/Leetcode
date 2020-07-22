class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //map用于建立相同异位词与对应string数组的映射
        unordered_map<string, vector<string>> ump;
        vector<vector<string>> res;
        int sz = strs.size();
        for (int i = 0; i < sz; ++i) {
            string str = strs[i];
            sort(str.begin(), str.end());
            ump[str].push_back(strs[i]);
            //cout << str << ", " << strs[i] << endl;
        }
        for (auto iter = ump.begin(); iter != ump.end(); ++iter) {
            //cout << iter->second.size() << endl;
            res.push_back(iter->second);
        }

        return res;
    }
};
