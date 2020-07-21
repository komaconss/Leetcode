class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int sz = nums.size();
        int i = sz - 2;
        //1.找到第一个逆序对
        while (i >= 0) {
            if (nums[i] < nums[i + 1]) {
                break;
            }
            --i;
        }

        if (i < 0) {
            reverse(nums.begin(), nums.end()); //没找到，说明整体从大到小排好序了，直接整体翻转即可
            return;
        }

        //2.交换从后往前第一个比当前值大的元素与当前值
        for (int j = sz - 1; j >= i; --j) {
            if (nums[j] > nums[i]) {
                swap(nums[i], nums[j]);
                break;
            }
        }

        //3.将这一部分的元素翻转
        reverse(nums.begin() + i + 1, nums.end());
    }
};
