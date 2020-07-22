class Solution {
public:
    bool canJump(vector<int>& nums) {
        int sz = nums.size();
        int mostReachPos = 0;
        int i = 0;
        while (i <= mostReachPos) {
            mostReachPos = max(mostReachPos, i + nums[i]);
            ++i;
            if (mostReachPos >= sz - 1) {
                return true;
            }    
        } 
        return false;         
    }
};
