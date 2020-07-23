class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        //采用回溯的方法
        int rows = board.size();
        int cols = board[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (dfs(board, i, j, 0, word)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, int i, int j, int pos, string& word) {
        if (board[i][j] != word[pos]) {
            return false;
        }

        if (word.size() - 1 == pos) {
            
            return true;
        }

        char tmp = board[i][j];
        board[i][j] = '0';
        ++pos;
        //从四个不同的方向来判断是否找到word
        if ((i >= 1 && dfs(board, i - 1, j, pos, word)) || //向上查找
            (i < board.size() - 1 && dfs(board, i + 1, j, pos, word)) || //向下查找
            (j >= 1 && dfs(board, i, j - 1, pos, word)) || //向左
            (j < board[0].size() - 1 && dfs(board, i, j + 1, pos, word))) { //向右
                return true;
        }
        board[i][j] = tmp;

        return false;
    }
};
