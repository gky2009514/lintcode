class Solution {
public:
    /**
     * Calculate the total number of distinct N-Queen solutions.
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    int totalNQueens(int n) {
        if (n <= 0)
            return 0;
        col = vector<bool>(n, false);
        l_to_r = vector<bool>(n << 1, false);
        r_to_l = vector<bool>(n << 1, false);
        this->n = n, count = 0;
        dfs(0);
        return count;
    }

private:
    int n, count;
    vector<bool> col, l_to_r, r_to_l;

    void dfs(int pos) {
        if (pos >= n) {
            count++;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!col[i] && !l_to_r[pos + i] &&
                !r_to_l[n - 1 - i + pos]) {
                col[i] = true;
                l_to_r[pos + i] = true;
                r_to_l[n - 1 - i + pos] = true;
                dfs(pos + 1);
                r_to_l[n - 1 - i + pos] = false;
                l_to_r[pos + i] = false;
                col[i] = false;
            }
        }
    }
};