class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return res;
        }

        int up = 0, down = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;

        while (true) {
            for (int i = left; i <= right; ++i) { //向右移动
                res.push_back(matrix[up][i]);
            }
            if (++up > down) {//判断上界是否已经大于下界
                break;
            }

            for (int i = up; i <= down; ++i) {
                res.push_back(matrix[i][right]);
            }
            if (--right < left) {
                break;
            }

            for (int i = right; i >= left; --i) {
                res.push_back(matrix[down][i]);
            }
            if (--down < up) {
                break;
            }

            for (int i = down; i >= up; --i) {
                res.push_back(matrix[i][left]);
            }
            if (++left > right) {
                break;
            }
        }

        return res;
    }
};
