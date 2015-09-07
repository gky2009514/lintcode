class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A) {
        n = static_cast<int>(A.size());
        for (int i = (n >> 1) - 1; i >= 0; i--)
            heap(A, i);
    }

private:
    int n;
    void heap(vector<int> &A, int p) {
        int l = (p << 1) + 1;
        if (l >= n)
            return;
        int r = l + 1 < n ? l + 1 : l;
        int np = A[l] < A[r] ? l : r;
        if (A[p] <= A[np])
            return;
        swap(A[p], A[np]);
        heap(A, np);
    }
};