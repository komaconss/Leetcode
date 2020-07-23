class Solution {
public:
    bool search(vector<int>& nums, int target) {
        //还是可以使用二分查找的方式，因为有重复元素，所以当nums[left] == nums[mid] == nums[right]时，
        //要注意处理的方法

        int sz = nums.size();
        int left = 0, right = sz - 1;
        int mid = 0;

        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return true;
            }

            if (nums[left] == nums[mid]) {
                ++left;
                continue;
            }

            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};
