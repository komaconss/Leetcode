class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> cur_vec;
        dfs(n, 0, k, cur_vec, res);
        return res;
    }
private:
    void dfs(int n, int pos, int k, vector<int>& cur_vec, vector<vector<int>>& res) {
        if (k == 0) {
            res.push_back(cur_vec);
            /*for (auto& e : cur_vec) {
                cout << e << " ";
            }
            cout << endl;*/
            return;
        }

        for (int i = pos + 1; i <= n; ++i) {
            //cout << "i = " << " " << i << endl; 
            cur_vec.push_back(i);
            dfs(n, i, k - 1, cur_vec, res);
            cur_vec.pop_back();
        }
    }
};
