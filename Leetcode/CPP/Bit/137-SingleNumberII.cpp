class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //用一个大小为32的数组统计每个元素在每一位上出现的次数，
        //之后对3取余，剩下的合到一起就是要求的结果

        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int cnt = 0;
            for (auto x : nums) {
                cnt += (x>>i)&1;
            }
            res |= (cnt%3)<<i;
        }
        return res;
    }
};
