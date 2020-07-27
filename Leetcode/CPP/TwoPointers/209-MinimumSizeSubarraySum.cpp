class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        //滑动窗口的方法来解决
        int sz = nums.size();
        if (sz == 0) {
            return 0;
        }
        int left = 0;
        int cur_sum = 0;
        int res = INT_MAX;
        for (int i = 0; i < sz; ++i) {
            cur_sum += nums[i];
            while (cur_sum >= s) {
                res = min(res, i - left + 1);
                cur_sum -= nums[left++];
            }
        }
        if (res == INT_MAX) {
            return 0;
        }
        return res;
    }
};
