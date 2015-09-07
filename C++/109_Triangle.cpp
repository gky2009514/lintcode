class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.size() == 1)
            return triangle[0][0];
        vector<vector<int> > sum(triangle.size(), vector<int>());
        sum[0].push_back(triangle[0][0]);
        int n = static_cast<int>(triangle.size());
        for (int i = 1; i < n; i++) {
            sum[i].push_back(sum[i - 1][0] + triangle[i][0]);
            int m = static_cast<int>(triangle[i].size());
            for (int j = 1; j < m - 1; j++)
                sum[i].push_back(min(sum[i - 1][j - 1], sum[i - 1][j]) + triangle[i][j]);
            sum[i].push_back(sum[i - 1][m - 2] + triangle[i][m - 1]);
        }
        int min_sum = INT_MAX;
        for (int i = 0; i < triangle[n - 1].size(); i++)
            min_sum = min(min_sum, sum[n - 1][i]);
        return min_sum;
    }
};