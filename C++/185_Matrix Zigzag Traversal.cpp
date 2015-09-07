class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @return: a vector of integers
     */
    vector<int> printZMatrix(vector<vector<int> > &matrix) {
        vector<int> res;
        int n = static_cast<int>(matrix.size());
        if (n == 0)
            return res;
        int m = static_cast<int>(matrix[0].size());
        if (m == 0)
            return res;
        int i = 0, j = 0;
        while (i < n && j < m) {
            while (i >= 0 && j < m) {
                res.push_back(matrix[i][j]);
                i--, j++;
            }
            if (j >= m) {
                j--;
                i += 2;
            } else {
                i++;
            }
            while (i < n && j >= 0) {
                res.push_back(matrix[i][j]);
                i++, j--;
            }
            if (i >= n) {
                i--;
                j += 2;
            } else {
                j++;
            }
        }
        return res;
    }
};