class Solution {
public:
    /**
     * @param A: An integer array.
     * @return: void
     */
    void rerange(vector<int> &A) {
        int n = static_cast<int>(A.size());
        if (n == 0)
            return;
        int neg = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] < 0)
                neg++;
        }
        int l = -2;
        if (neg < n - neg)
            l = -1;
        for (int i = 0; i < n; i++) {
            while (l + 2 < n && A[l + 2] < 0)
                l += 2;
            if (l + 2 >= n)
                break;
            if (A[i] > 0)
                continue;
            if (i > l || (abs(i - l) & 1)) {
                l += 2;
                swap(A[l], A[i]);
            }
        }
    }
};