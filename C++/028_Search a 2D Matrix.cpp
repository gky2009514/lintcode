class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int n = static_cast<int>(matrix.size());
        int m = static_cast<int>(matrix[0].size());
        if (target < matrix[0][0] || target > matrix[n - 1][m - 1])
            return false;
        this->target = target;
        if (searchRow(matrix, 0, n - 1))
            return true;
        return searchCol(matrix, 0, m - 1);
    }

private:
    int target, pos;

    bool searchRow(vector<vector<int> > &matrix, int l, int r) {
        if (l > r) {
            pos = r;
            return false;
        }
        int mid = l + ((r - l) >> 1);
        if (matrix[mid][0] == target)
            return true;
        else if (matrix[mid][0] < target)
            return searchRow(matrix, mid + 1, r);
        else
            return searchRow(matrix, l, mid - 1);
    }

    bool searchCol(vector<vector<int> > &matrix, int l, int r) {
        if (l > r)
            return false;
        int mid = l + ((r - l) >> 1);
        if (matrix[pos][mid] == target)
            return true;
        else if (matrix[pos][mid] < target)
            return searchCol(matrix, mid + 1, r);
        else
            return searchCol(matrix, l, mid - 1);
    }
};