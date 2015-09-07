class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        int n = static_cast<int>(values.size());
        vector<vector<int> > dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            dp[i][i] = values[i];
        for (int j = 1; j < n; j++) {
            for (int i = 0; i < n - j; i++)
                dp[i][i + j] = max(values[i] - dp[i + 1][i + j],
                                   values[i + j] - dp[i][i + j - 1]);
        }
        return dp[0][n - 1] > 0;
    }
};