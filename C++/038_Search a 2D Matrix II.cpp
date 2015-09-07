class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        int n = static_cast<int>(matrix.size());
        int m = static_cast<int>(matrix[0].size());
        int row = 0, col = m - 1, count = 0;
        while (row < n && col >= 0) {
            if (matrix[row][col] < target) {
                row++;
            } else if (matrix[row][col] > target) {
                col--;
            } else {
                row++, col--;
                count++;
            }
        }
        return count;
    }
};