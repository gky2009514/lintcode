class Solution {
public:
    /**
     * @param A an integer matrix
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequenceII(vector<vector<int>>& A) {
        n = static_cast<int>(A.size());
        if (n == 0)
            return 0;
        m = static_cast<int>(A[0].size());
        if (m == 0)
            return 0;
        dp = vector<vector<int> >(n, vector<int>(m, -1));
        int len = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                len = max(len, dfs(i, j, A));
        }
        return len;
    }

private:
    static const int N = 4;
    int direct[N][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int n, m;
    vector<vector<int> > dp;
    int dfs(int x, int y, const vector<vector<int> > &A) {
        if (dp[x][y] != -1)
            return dp[x][y];
        dp[x][y] = 1;
        for (int i = 0; i < N; i++) {
            int nx = x + direct[i][0];
            int ny = y + direct[i][1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (A[nx][ny] > A[x][y])
                dp[x][y] = max(dp[x][y], 1 + dfs(nx, ny, A));
        }
        return dp[x][y];
    }
};