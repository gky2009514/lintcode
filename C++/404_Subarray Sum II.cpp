class Solution {
public:
    /**
     * @param A an integer array
     * @param start an integer
     * @param end an integer
     * @return the number of possible answer
     */
    int subarraySumII(vector<int>& A, int start, int end) {
        int n = static_cast<int>(A.size());
        vector<int> sum(n + 1, 0);
        for (int i = 0; i < n; i++)
            sum[i + 1] = sum[i] + A[i];
        int num = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                if (sum[j] - sum[i - 1] >= start &&
                    sum[j] - sum[i - 1] <= end)
                    num++;
            }
        }
        return num;
    }
};