class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int sz = nums.size();
        set<long> st;

        for (int i = 0; i < sz; ++i) {
            auto iter = st.lower_bound((long)nums[i] - t);
            if (iter != st.end() && *iter <= (long)nums[i] + t) {
                return true;
            }
            st.insert(nums[i]);
            if (st.size() == k + 1) {
                st.erase(nums[i - k]);
            }
        }
        return false;
    }
};
