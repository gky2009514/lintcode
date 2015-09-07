class Solution {
public:
    /**
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
    int smallestDifference(vector<int> &A, vector<int> &B) {
        int n = static_cast<int>(A.size());
        int m = static_cast<int>(B.size());
        if (n == 0 || m == 0)
            return 0;
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int i = 0, j = 0, mi = INT_MAX;
        while (i < n && j < m) {
            mi = min(mi, abs(A[i] - B[j]));
            if (A[i] <= B[j])
                i++;
            else
                j++;
        }
        return mi;
    }
};