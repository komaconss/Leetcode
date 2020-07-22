class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int sz = intervals.size();
        if (sz == 0) {
            return res;
        }
        sort(intervals.begin(), intervals.end());

        res.push_back(intervals[0]);
        for (int i = 1; i < sz; ++i) {
            int cur_end_pos = res.back()[1];
            if (intervals[i][0] > cur_end_pos) {
                res.push_back(intervals[i]);
            } else {
                res.back()[1] = max(cur_end_pos, intervals[i][1]);
            }
        }
        return res;
    }
};
