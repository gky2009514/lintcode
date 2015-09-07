class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        if (A.length() == 0 || B.length() == 0)
            return 0;
        int n = static_cast<int>(A.length());
        int m = static_cast<int>(B.length());
        vector<vector<int> > dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            dp[i][0] = A[i] == B[0];
        for (int i = 1; i < m; i++)
            dp[0][i] = B[i] == A[0];
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (A[i] == B[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n - 1][m - 1];
    }
};