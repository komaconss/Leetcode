class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();
        vector<int> res(sz, 1);
        if (0 == sz) {
            return res;
        }

        vector<int> left(sz, 1);//left[i]表示0~i-1的乘积
        vector<int> right(sz, 1);//right[i]表示i+1~sz-1的乘积
        for (int i = 1; i < sz; ++i) {
            left[i] = left[i - 1] * nums[i - 1];
        }
        for (int i = sz - 2; i >= 0; --i) {
            right[i] = right[i + 1] * nums[i + 1];
        }
        //res[0] = right[0];
        //res[sz - 1] = left[sz - 1];
        for (int i = 0; i < sz; ++i) {
            res[i] = left[i] * right[i];
        }
        return res;

    }
};
