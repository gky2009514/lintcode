class Solution {
public:
    /**
     * @param A: sorted integer array A which has m elements,
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        int ai = m - 1, bi = n - 1, ri = m + n - 1;
        while (ai >= 0 && bi >= 0) {
            if (A[ai] > B[bi])
                A[ri--] = A[ai--];
            else
                A[ri--] = B[bi--];
        }
        while (bi >= 0)
            A[ri--] = B[bi--];
    }
};