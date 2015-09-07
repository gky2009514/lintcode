class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        if (m <= 0)
            return 0;
        vector<int> dp(m + 1, 0);
        for (int i = 0; i < A.size(); i++) {
            for (int j = m; j >= A[i]; j--)
                dp[j] = max(dp[j], dp[j - A[i]] + A[i]);
        }
        return dp[m];
    }
};