class Solution {
public:
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        if (T.length() == 0 || S.length() < T.length())
            return 0;
        vector<int> dp(S.length(), 0);
        dp[0] = S[0] == T[0];
        for (int i = 1; i < S.length(); i++)
            dp[i] = dp[i - 1] + (S[i] == T[0] ? 1 : 0);
        vector<int> next(S.length(), 0);
        for (int i = 1; i < T.length(); i++) {
            if (dp[i - 1] && S[i] == T[i])
                next[i] = 1;
            for (int j = i + 1; j < S.length(); j++) {
                next[j] = next[j - 1];
                if (S[j] == T[i])
                    next[j] += dp[j - 1];
            }
            dp = next;
            next = vector<int>(S.length(), 0);
        }
        return dp[S.length() - 1];
    }
};