class Solution {
public:
    /**
     * @param A: An integer array
     * @return: The number of element in the array that
     *          are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        vector<int> res;
        n = static_cast<int>(A.size());
        m = static_cast<int>(queries.size());
        if (m == 0)
            return res;
        sort(A.begin(), A.end());
        this->A = A;
        for (int i = 0; i < m; i++)
            res.push_back(binaryCount(queries[i]));
        return res;
    }

private:
    int n, m;
    vector<int> A;
    int binaryCount(int num) {
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (A[mid] < num)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l;
    }
};