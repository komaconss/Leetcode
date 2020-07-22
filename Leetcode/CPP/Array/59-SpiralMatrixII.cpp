class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        if (n == 0) {
            return res;
        }

        int up = 0, down = n - 1;
        int left = 0, right = n - 1;

        int k = 1;
        while (k <= n * n) {
            for (int i = left; i <= right; ++i) { //向右移动
                res[up][i] = k++;
            }
            if (++up > down) {//判断上界是否已经大于下界
                break;
            }

            for (int i = up; i <= down; ++i) {
                res[i][right] = k++;
            }
            if (--right < left) {
                break;
            }

            for (int i = right; i >= left; --i) {
                res[down][i] = k++;
            }
            if (--down < up) {
                break;
            }

            for (int i = down; i >= up; --i) {
                res[i][left] = k++;
            }
            if (++left > right) {
                break;
            }
        }

        return res;
    }
};
