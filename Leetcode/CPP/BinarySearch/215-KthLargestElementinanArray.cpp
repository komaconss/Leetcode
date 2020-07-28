class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int sz = nums.size();
        //利用快排的partition方法来寻找
        int left = 0, right = sz - 1;
        int mid = 0;
        int target = sz - k;
        while (left <= right) {
            int pos = partition(nums, left, right);
            if (pos == target) {
                return nums[pos];
            } else if (pos < target) {
                left = pos + 1;
            } else {
                right = pos - 1;
            }
        }
        return -1;
    }
private:
    int partition(vector<int>& nums, int left, int right) {
        int val = nums[left];
        while (left < right) {
            while (left < right && nums[right] >= val) {
                --right;
            }
            if (left < right) {
                nums[left] = nums[right];
            }            
            while (left < right && nums[left] <= val) {
                ++left;
            }
            if (left < right) {
                nums[right] = nums[left];
            }            
        }
        nums[left] = val;
        return left;
    }
};
