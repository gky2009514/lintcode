class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        int len = 0, n = static_cast<int>(A.size());
        if (n <= 1)
            return n;
        for (int i = 0; i < n; ) {
            int j = i + 1;
            while (j < n && A[j - 1] < A[j])
                j++;
            len = max(len, j - i);
            i = j;
        }
        for (int i = n - 1; i >= 0; ) {
            int j = i - 1;
            while (j >= 0 && A[j] > A[j + 1])
                j--;
            len = max(len, i - j);
            i = j;
        }
        return len;
    }
};