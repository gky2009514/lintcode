class Solution {
public:
    /**
    * @param matrix: a matrix of 0 and 1
    * @return: an integer
    */
    int maxSquare(vector<vector<int> > &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        int n = static_cast<int>(matrix.size());
        int m = static_cast<int>(matrix[0].size());
        vector<vector<int> > area(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++)
                area[i][j] = area[i - 1][j] + area[i][j - 1] -
                            area[i - 1][j - 1] + matrix[i - 1][j - 1];
        }
        for (int k = min(n, m); k > 0; k--) {
            int ak = k * k;
            for (int i = 1; i <= n - k + 1; i++) {
                for (int j = 1; j <= m - k + 1; j++) {
                    if (area[i + k - 1][j + k - 1] - area[i + k - 1][j - 1] -
                        area[i - 1][j + k - 1] + area[i - 1][j - 1] == ak)
                        return ak;
                }
            }
        }
        return 0;
    }
};