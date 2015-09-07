class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void setZeroes(vector<vector<int> > &matrix) {
        int n = static_cast<int>(matrix.size());
        if (n == 0)
            return;
        int m = static_cast<int>(matrix[0].size());
        if (m == 0)
            return;
        bool row = false, col = false;
        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == 0)
                col = true;
        }
        for (int i = 0; i < m; i++) {
            if (matrix[0][i] == 0)
                row = true;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        if (row) {
            for (int i = 0; i < m; i++)
                matrix[0][i] = 0;
        }
        if (col) {
            for (int i = 0; i < n; i++)
                matrix[i][0] = 0;
        }
    }
};