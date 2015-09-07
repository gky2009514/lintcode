class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        if (values.size() <= 2)
            return true;
        int n = static_cast<int>(values.size());
        vector<int> dp(n + 1, 0);
        dp[n - 1] = values[n - 1];
        for (int i = n - 2; i >= 0; i--)
            dp[i] = max(values[i] - dp[i + 1], values[i] + values[i + 1] - dp[i + 2]);
        return dp[0] > 0;
    }
};