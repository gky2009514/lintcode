class Solution {
public:
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        if (A.length() == 0 || B.length() == 0)
            return 0;
        int N = static_cast<int>(A.length());
        int M = static_cast<int>(B.length());
        vector<vector<int> > dp(N, vector<int>(M, 0));
        int res = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] == B[0])
                res = dp[i][0] = 1;
        }
        for (int i = 0; i < M; i++) {
            if (A[0] == B[i])
                res = dp[0][i] = 1;
        }
        for (int i = 1; i < N; i++) {
            for (int j = 1; j < M; j++) {
                if (A[i] == B[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    res = max(res, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return res;
    }
};