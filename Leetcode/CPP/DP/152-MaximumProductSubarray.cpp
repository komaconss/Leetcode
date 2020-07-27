class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int sz = nums.size();
        int maxP = nums[0], minP = nums[0], res = nums[0];
        for (int i = 1; i < sz; ++i) {
            int minCur = minP, maxCur = maxP;
            maxP = max(maxCur * nums[i], max(minCur * nums[i], nums[i]));
            minP = min(maxCur * nums[i], min(minCur * nums[i], nums[i]));
            res = max(maxP, res);
        }
        return res;
    }
};
