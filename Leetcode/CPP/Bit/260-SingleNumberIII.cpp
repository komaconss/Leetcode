class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        //先通过异或操作找到两个只出现一次元素的异或值
        //找到该值第一个为1的位置
        //遍历数组，将所有元素分为两组，按上面找到的位置是否为1来分组，同时执行异或操作找到这两个元素

        int sz = nums.size();
        vector<int> res;
        if (sz == 0) {
            return res;
        }
        int val = 0;
        for (int i = 0; i < sz; ++i) {
            val ^= nums[i];
        }
        int pos = 0;
        while (val) {
            if ((val & 1) == 1) {
                break;
            }
            val >>= 1;
            ++pos;
        }
        int a = 0, b = 0;
        for (int i = 0; i < sz; ++i) {
            if ((nums[i] >> pos) & 1) {
                a ^= nums[i];
            } else {
                b ^= nums[i];
            }
        }
        res.push_back(a);
        res.push_back(b);
        return res;
    }
};
