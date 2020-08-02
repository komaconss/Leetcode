class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> ump_1;
        unordered_map<int, vector<int>> ump_2;
        int max_count = 0;
        for (auto& elem : nums) {
            ++ump_1[elem];
            max_count = max(max_count, ump_1[elem]);
        }
        //cout << "max_count = " << max_count << endl;
        for (auto iter = ump_1.begin(); iter != ump_1.end(); ++iter) {
            ump_2[iter->second].push_back(iter->first);
        }
        /*for (auto iter : ump_2) {
            for (auto num : iter.second) {
                cout << num << ", ";
            }
            cout << endl;
        }*/

        for (int i = max_count; i >= 1; --i) {
            if (ump_2.find(i) == ump_2.end()) {
                continue;
            }
           for (auto num : ump_2[i]) {
                res.push_back(num);
                //cout << "num = " << num << ", size = " << res.size() << endl;
                if (res.size() == k) {
                    return res;
                }
            }
        }
        return res;
    }
};
