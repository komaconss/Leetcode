class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = 0;
        int dis = INT_MAX;
        int sz = nums.size();
        if (sz < 0) {
            return res;
        }
        sort(nums.begin(), nums.end());

        for (int i = 0; i < sz; ++i) {
            int left = i + 1, right = sz - 1;
            while (left < right) {
                int sum = nums[left] + nums[right] + nums[i];
                if (sum == target) {
                    cout << "equal" << endl;
                    return sum;
                }                
                if (sum > target) {
                    --right;
                }
                if (sum < target) {
                    ++left;
                }
                //cout << "sum = " << sum << ", target = " << target << endl;
                if (abs(sum - target) < dis) {
                    dis = abs(sum - target);
                    res = sum;
                }
            }
        }
        return res;
    }
};
