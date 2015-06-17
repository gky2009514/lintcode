class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        vector<int> res;
        if (A.size() > B.size())
            res = vector<int>(A);
        else
            res = vector<int>(B);
        res.resize(A.size() + B.size());
        int i = static_cast<int>(A.size()) - 1;
        int j = static_cast<int>(B.size()) - 1;
        int k = static_cast<int>(res.size()) - 1;
        while (i >= 0 && j >= 0) {
            if (A[i] > B[j])
                res[k--] = A[i--];
            else
                res[k--] = B[j--];
        }
        if (A.size() > B.size()) {
            while (j >= 0)
                res[k--] = B[j--];
        } else {
            while (i >= 0)
                res[k--] = A[i--];
        }
        return res;
    }
};