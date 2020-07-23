class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //根据题意，矩阵可以转换为一个排序的数组，需要计算一下下标值，用二分查找法来
        //找target
        int rows = matrix.size();
        if (rows == 0) {
            return false;
        }
        int cols = matrix[0].size();
        if (cols == 0) {
            return false;
        }

        int left = 0, right = rows * cols - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int val = matrix[mid/cols][mid%cols];
            if (val > target) {
                right = mid - 1;
            } else if (val < target) {
                left = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
