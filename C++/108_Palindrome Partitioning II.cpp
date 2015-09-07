class Solution {
public:
    /**
     * @param s a string
     * @return an integer
     */
    int minCut(string s) {
        int n = static_cast<int>(s.length());
        if (n <= 1)
            return 0;
        vector<vector<bool> > isPal(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++)
            isPal[i][i] = true;
        for (int i = 0; i < n - 1; i++)
            isPal[i][i + 1] = s[i] == s[i + 1];
        for (int j = 3; j <= n; j++) {
            for (int i = 0; i <= n - j; i++) {
                if (s[i] == s[i + j - 1] && isPal[i + 1][i + j - 2])
                    isPal[i][i + j - 1] = true;
            }
        }
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            if (isPal[0][i]) {
                dp[i] = 0;
                continue;
            }
            dp[i] = dp[i - 1] + 1;
            for (int j = i - 1; j > 0; j--) {
                if (isPal[j][i])
                    dp[i] = min(dp[i], dp[j - 1] + 1);
            }
        }
        return dp[n - 1];
    }
};