class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //转换成有环链表寻找入口节点的方法
        int sz = nums.size();
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
