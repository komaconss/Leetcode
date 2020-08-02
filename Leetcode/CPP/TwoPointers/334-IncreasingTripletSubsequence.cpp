class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int sz = nums.size();
        if (sz < 3) {
            return false;
        }
        int small = INT_MAX;
        int mid = INT_MAX;
        for (int i = 0; i < sz; ++i) {
            if (nums[i] <= small) {
                small = nums[i];
            } else if (nums[i] <= mid) {
                mid = nums[i];
            } else if (nums[i] > mid) {
                return true;
            }
        }
        return false;

    }
};
