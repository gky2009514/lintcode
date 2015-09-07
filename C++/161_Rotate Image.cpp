class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void rotate(vector<vector<int> > &matrix) {
        int n = static_cast<int>(matrix.size());
        if (n == 0)
            return;
        int i = 0, j = n - 1;
        while (i < j) {
            for (int k = 0; k < n; k++)
                swap(matrix[i][k], matrix[j][k]);
            i++, j--;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++)
                swap(matrix[i][j], matrix[j][i]);
        }
    }
};