class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res{-1, -1};
        int sz = nums.size();
        int left = 0, right = sz - 1;
        int mid = 0;
        //1.寻找重复数组中的lower_bound
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if (left < sz && nums[left] == target) {
            res[0] = left;
        }

        //2.寻找重复数组中的upper_bound
        left = 0, right = sz - 1;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (right >= 0 && nums[right] == target) {
            res[1] = right;
        }

        return res;
    }
};
