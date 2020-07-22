class Solution {
public:
    int maxArea(vector<int>& height) {
        //双指针，开始时最大面积是（最大的底乘以二者中的较大值）；
        //之后要比这个值更大，只能是增加高度
        int sz = height.size();
        int res = 0;
        int left = 0, right = sz - 1;
        while (left < right) {
            int curArea = (right - left) * min(height[left], height[right]);
            res = max(curArea, res);
            if (height[left] > height[right]) {
                --right;
            } else {
                ++left;
            }
        }
        return res;
    }
};
