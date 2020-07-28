class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int sz = nums.size();
        vector<string> res;
        string str;
        int k = 0; //k是每个区间的起点
        for (int i = 0; i < sz; ++i) {
            if (i + 1 < sz && nums[i] + 1 == nums[i + 1]) {
                continue;
            } else {
                if (i == k) { //区间中只有一个值的情况
                    res.push_back(to_string(nums[i]));
                } else {
                    string str = to_string(nums[k]) + "->" + to_string(nums[i]);
                    res.push_back(str);
                }
            }
            k = i + 1;
        }
        return res;
    }
};
