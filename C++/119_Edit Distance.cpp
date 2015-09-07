class Solution {
public:
    /**
     * @param word1 & word2: Two string.
     * @return: The minimum number of steps.
     */
    int minDistance(string word1, string word2) {
        n = static_cast<int>(word1.length());
        m = static_cast<int>(word2.length());
        if (n == 0 || m == 0)
            return n == 0 ? m : n;
        w1 = word1, w2 = word2;
        dp = vector<vector<int> >(n + 1, vector<int>(m + 1, -1));
        return dfs(0, 0);
    }

private:
    int n, m;
    string w1, w2;
    vector<vector<int> > dp;

    int dfs(int np, int mp) {
        if (dp[np][mp] != -1)
            return dp[np][mp];
        if (np >= n) {
            dp[np][mp] = m - mp;
            return dp[np][mp];
        } else if (mp >= m) {
            dp[np][mp] = n - np;
            return dp[np][mp];
        } else {
            if (w1[np] == w2[mp])
                dp[np][mp] = dfs(np + 1, mp + 1);
            else
                dp[np][mp] = min(dfs(np + 1, mp + 1),
                                 min(dfs(np + 1, mp), dfs(np, mp + 1))) + 1;
        }
        return dp[np][mp];
    }
};