class Solution {
public:
    int search(vector<int>& nums, int target) {
        int sz = nums.size();
        int left = 0, right = sz - 1;
        int mid = 0;

        while (left <= right) {
            mid = left + (right - left) / 2;
            //1.判断mid的两侧有序的部分
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[sz - 1]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};
