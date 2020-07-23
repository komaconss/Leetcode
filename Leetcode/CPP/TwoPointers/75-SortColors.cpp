class Solution {
public:
    void sortColors(vector<int>& nums) {
        int sz = nums.size();

        int i = 0, j = sz, k = -1;
        //双指针保持边界
        while (i < j) {
            //cout << "i = " << i << endl;
            /*for (auto& elem : nums) {
                cout << elem << " ";
            }
            cout << endl;*/
            if (nums[i] == 0) {
                swap(nums[i++], nums[++k]);
            } else if (nums[i] == 2) {
                swap(nums[i], nums[--j]);
            } else {
                ++i;
            }
        }
    }
};
