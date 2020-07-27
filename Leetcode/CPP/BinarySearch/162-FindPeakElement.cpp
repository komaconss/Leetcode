class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 1) {
            return 0;
        }
    
        int left = 0, right = sz - 1;
        int mid = 0;
        while (left < right) {//注意这里需要是小于，用来保证[left, right]区间至少大小为2
            mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
