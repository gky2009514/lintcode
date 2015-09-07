class Solution {
public:
    /**
    * @param A an integer array
    * @param k an integer
    * @return an integer
    */
    int postOffice(vector<int>& A, int k) {
        if (A.size() == 0 || k <= 0 || k >= A.size())
            return 0;
        sort(A.begin(), A.end());
        int n = static_cast<int>(A.size());
        vector<vector<int> > dist(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int mid = (i + j) >> 1;
                for (int l = i; l <= mid; l++)
                    dist[i][j] += A[mid] - A[l];
                for (int l = mid + 1; l <= j; l++)
                    dist[i][j] += A[l] - A[mid];
            }
        }
        vector<vector<int> > dp(n, vector<int>(k, 0));
        for (int i = 0; i < n; i++)
            dp[i][0] = dist[0][i];
        for (int j = 1; j < k; j++) {
            for (int i = n - 1; i >= j; i--) {
                dp[i][j] = INT_MAX;
                for (int l = i; l >= j; l--)
                    dp[i][j] = min(dp[i][j], dp[l - 1][j - 1] + dist[l][i]);
            }
        }
        return dp[n - 1][k - 1];
    }
};