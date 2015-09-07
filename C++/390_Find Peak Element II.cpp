class Solution {
public:
    /**
     * @param A: An integer matrix
     * @return: The index of the peak
     */
    vector<int> findPeakII(vector<vector<int> > A) {
        vector<int> pos;
        int n = static_cast<int>(A.size());
        if (n <= 2)
            return pos;
        int m = static_cast<int>(A[0].size());
        if (m <= 2)
            return pos;
        int lr = 0, rr = n - 1, lc = 0, rc = m - 1;
        while (lr <= rr && lc <= rc) {
            int mr = lr + ((rr - lr) >> 1);
            int ma = INT_MIN, x = 0, y = 0;
            for (int i = lc; i <= rc; i++) {
                if (A[mr][i] > ma) {
                    ma = A[mr][i];
                    x = mr, y = i;
                }
            }
            int mc = lc + ((rc - lc) >> 1);
            for (int i = lr; i <= rr; i++) {
                if (A[i][mc] > ma) {
                    ma = A[i][mc];
                    x = i, y = mc;
                }
            }
            if (check(A, x, y)) {
                pos.push_back(x);
                pos.push_back(y);
                break;
            }
            if (x == mr) {
                if (A[x - 1][y] > A[x + 1][y])
                    rr = mr - 1;
                else
                    lr = mr + 1;
                if (y < mc)
                    rc = mc - 1;
                else
                    lc = mc + 1;
            } else {
                if (A[x][y - 1] > A[x][y + 1])
                    rc = mc - 1;
                else
                    lc = mc + 1;
                if (x < mr)
                    rr = mr - 1;
                else
                    lr = mr + 1;
            }
        }
        return pos;
    }

private:
    bool check(const vector<vector<int> > A, int x, int y) {
        return A[x][y] > A[x - 1][y] && A[x][y] > A[x + 1][y] &&
                A[x][y] > A[x][y - 1] && A[x][y] > A[x][y + 1];
    }
};