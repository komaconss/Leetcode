class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool flag = false;
        int rows = matrix.size();
        int cols = matrix[0].size();

        //1.通过第一列更新第一行和第一列
        for (int i = 0; i < rows; ++i) {
            if (matrix[i][0] == 0) {
                flag = true;
            }
            for (int j = 1; j < cols; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        //2.更新其他数据
        for (int i = rows - 1; i >= 0; --i) {
            for (int j = cols - 1; j >= 1; --j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
            if (flag) {
                matrix[i][0] = 0;
            }
        }
    }
};
