class Solution {
public:
    int findMin(vector<int>& nums) {
        //采用二分查找的方法
        int sz = nums.size();
        if (sz == 1) {
            return nums[0];
        }
        int left = 0, right = sz - 1;
        if (nums[left] < nums[right]) {
            return nums[0];
        }
        int mid = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1]) {
                return nums[mid + 1];
            }
            if (nums[mid] < nums[mid - 1]) {
                return nums[mid];
            }
            if (nums[mid] < nums[0]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};
