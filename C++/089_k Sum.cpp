class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
    int kSum(vector<int> A, int k, int target) {
        int n = static_cast<int>(A.size());
        if (n == 0)
            return 0;
        vector<vector<vector<int> > > dp(n + 1,
            vector<vector<int> >(k + 1, vector<int>(target + 1, 0)));
        for (int i = 0; i < n; i++) {
            if (A[i] <= target) {
                for (int j = i; j < n; j++)
                    dp[j + 1][1][A[i]] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 2; j <= k; j++) {
                for (int l = 0; l < A[i]; l++)
                    dp[i + 1][j][l] = dp[i][j][l];
                for (int l = A[i]; l <= target; l++)
                    dp[i + 1][j][l] = dp[i][j - 1][l - A[i]] + dp[i][j][l];
            }
        }
        return dp[n][k][target];
    }
};