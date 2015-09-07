class Solution {
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length())
            return false;
        int n = static_cast<int>(s1.length());
        int m = static_cast<int>(s2.length());
        vector<vector<bool> > dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; i++)
            dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
        for (int i = 1; i <= m; i++)
            dp[0][i] = dp[0][i - 1] && s2[i - 1] == s3[i - 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if ((dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
                    (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]))
                    dp[i][j] = true;
            }
        }
        return dp[n][m];
    }
};