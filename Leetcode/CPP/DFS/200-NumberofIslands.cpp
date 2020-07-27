class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        //从任意一个元素为1的位置出发，进行dfs遍历
        int rows = grid.size();
        if (rows == 0) {
            return 0;
        }
        int cols = grid[0].size();

        int res = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ++res;
                }                
            }
        }

        return res;
    }
private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i > grid.size() - 1 || j < 0 || j > grid[0].size() - 1 || grid[i][j] == '0') {
            return;
        }

        grid[i][j] = '0';
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }
};
