class Solution {
public:
    /**
     * @param A: An integer array.
     * @param target: An integer.
     */
    int MinAdjustmentCost(vector<int> A, int target) {
        if (A.size() == 0)
            return 0;
        int n = static_cast<int>(A.size());
        vector<vector<int> > dp(n, vector<int>(N + 1, 0));
        for (int i = 1; i <= N; i++)
            dp[0][i] = abs(i - A[0]);
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= N; j++) {
                dp[i][j] = INT_MAX;
                int c = abs(A[i] - j);
                for (int k = 1; k <= N; k++) {
                    if (abs(k - j) > target)
                        continue;
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + c);
                }
            }
        }
        int mi = INT_MAX;
        for (int i = 1; i <= N; i++)
            mi = min(mi, dp[n - 1][i]);
        return mi;
    }

private:
    const int N = 100;
};