class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //选择右上角或者左下角开始遍历
        int rows = matrix.size();
        if (rows == 0) {
            return false;
        }
        int cols = matrix[0].size();
        int i = 0, j = cols - 1;
        while (i >= 0 && i < rows && j >= 0 && j < cols) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] < target) {
                ++i;
            } else {
                --j;
            }
        }
        return false;
    }
};
