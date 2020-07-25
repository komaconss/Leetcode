class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if (rows == 0) {
            return;
        }
        int cols = board[0].size();

        //1.将从边界出发的O所经过的全是O的路径中的O全改为#
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (i == 0 || j == 0 || i == rows - 1 || j == cols - 1) {
                    if (board[i][j] == 'O') {
                        //cout << "begin to search, i = " << i << ", j = " << j << endl;
                        dfs(board, i, j);
                    }
                }
            }
        }

        //2.将所有的O改为X，并将所有的#改为O
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }

private:
    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || j < 0 || i > board.size() - 1 || j > board[0].size() - 1 || board[i][j] == 'X' || board[i][j] == '#') {
            return;
        }
        //cout << "i = " << i << ", j = " << j << endl;
        if (board[i][j] == 'O') {
            board[i][j] = '#';
        }

        dfs(board, i - 1, j);
        dfs(board, i + 1, j);
        dfs(board, i, j - 1);
        dfs(board, i, j + 1);
    }
};
