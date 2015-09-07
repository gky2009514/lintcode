class Solution {
public:
    /**
     * @param s1 A string
     * @param s2 Another string
     * @return whether s2 is a scrambled string of s1
     */
    bool isScramble(string& s1, string& s2) {
        if (s1.length() != s2.length())
            return false;
        int n = static_cast<int>(s1.length());
        if (n == 0)
            return true;
        vector<vector<vector<bool> > > dp(n + 1,
            vector<vector<bool> >(n, vector<bool>(n, false)));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                dp[1][i][j] = s1[i] == s2[j];
        }
        for (int k = 2; k <= n; k++) {
            for (int i = 0; i <= n - k; i++) {
                for (int j = 0; j <= n - k; j++) {
                    for (int l = 1; l < k; l++) {
                        if ((dp[l][i][j] && dp[k - l][i + l][j + l]) ||
                            (dp[l][i][j + k - l] && dp[k - l][i + l][j])) {
                            dp[k][i][j] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[n][0][0];
    }
};