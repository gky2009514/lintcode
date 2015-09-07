class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> A, vector<int> B) {
        n = static_cast<int>(A.size());
        m = static_cast<int>(B.size());
        if ((n + m) & 1)
            return binaryFind(A, 0, n, B, 0, m, (n + m) / 2 + 1);
        else
            return (binaryFind(A, 0, n, B, 0, m, (n + m) / 2) +
                    binaryFind(A, 0, n, B, 0, m, (n + m) / 2 + 1)) / 2.0;
    }

private:
    int n, m;
    double binaryFind(const vector<int> &A, int pa, int la,
                      const vector<int> &B, int pb, int lb, int k) {
        if (lb > la)
            return binaryFind(B, pb, lb, A, pa, la, k);
        if (lb == 0)
            return A[pa + k - 1];
        if (k == 1)
            return min(A[pa], B[pb]);
        int j = min(k >> 1, lb), i = k - j;
        if (A[pa + i - 1] < B[pb + j - 1])
            return binaryFind(A, pa + i, la - i, B, pb, j, k - i);
        else if (A[pa + i - 1] > B[pb + j - 1])
            return binaryFind(A, pa, i, B, pb + j, lb - j, k - j);
        return A[pa + i - 1];
    }
};