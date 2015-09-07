class Solution {
public:
    /**
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string '...Q' shows a queen on forth position
     */
    vector<vector<string> > solveNQueens(int n) {
        solve.clear();
        board = vector<string>(n, string(n, '.'));
        col = vector<bool>(n, false);
        l_to_r = vector<bool>(n << 1, false);
        r_to_l = vector<bool>(n << 1, false);
        dfs(0, n);
        return solve;
    }

private:
    vector<vector<string> > solve;
    vector<string> board;
    vector<bool> col, l_to_r, r_to_l;

    void dfs(int pos, int n) {
        if (pos >= n) {
            solve.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!col[i] && !l_to_r[pos + i] && !r_to_l[n - 1 - i + pos]) {
                col[i] = true;
                l_to_r[pos + i] = true;
                r_to_l[n - 1 - i + pos] = true;
                board[pos][i] = 'Q';
                dfs(pos + 1, n);
                board[pos][i] = '.';
                r_to_l[n - 1 - i + pos] = false;
                l_to_r[pos + i] = false;
                col[i] = false;
            }
        }
    }
};