class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //双指针的方法
        int sz = nums.size();
        if (sz == 0) {
            return sz;
        }
        int k = 0;
        int num = nums[0];
        int count = 1;
        for (int i = 1; i < sz; ++i) {
            if (nums[i] == num) {
                if (count == 1) {
                    ++count;
                    nums[++k] = nums[i];
                } else {
                    continue;
                }
            } else {
                num = nums[i];
                count = 1;
                nums[++k] = nums[i];
            }
        }
        return k + 1;
    }
};
