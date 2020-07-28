class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int sz = nums.size();
        vector<int> res;
        if (sz == 0) {
            return res;
        }
        int a = 0, b = 0;
        int count_a = 0, count_b = 0;
        for (int i = 0; i < sz; ++i) {
            if (nums[i] == a) {
                ++count_a;
            } else if (nums[i] == b) {
                ++count_b;
            } else if (count_a == 0) {
                a = nums[i];
                ++count_a;
            } else if (count_b == 0) {
                b = nums[i];
                ++count_b;
            } else {
                --count_a;
                --count_b;
            }
        }
        count_a = 0;
        count_b = 0;
        for (int i = 0; i < sz; ++i) {
            if (nums[i] == a) {
                ++count_a;
            } else if (nums[i] == b) {
                ++count_b;
            }
        }
        
        if (count_a > sz / 3) {
            res.push_back(a);
        }

        if (count_b > sz / 3) {
            res.push_back(b);
        }
        return res;
    }
;
