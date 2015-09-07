class Solution {
public:
    /**
    * @param matrix an integer matrix
    * @return the coordinate of the left-up and right-down number
    */
    vector<vector<int>> submatrixSum(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return vector<vector<int> >();
        int n = static_cast<int>(matrix.size());
        int m = static_cast<int>(matrix[0].size());
        vector<vector<int> >sum(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++)
                sum[i][j] = sum[i][j - 1] + sum[i - 1][j] -
                            sum[i - 1][j - 1] + matrix[i - 1][j - 1];
        }
        vector<vector<int> > res;
        map<int, int> mp;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                mp.clear();
                for (int k = 1; k <= m; k++) {
                    int s = sum[j][k] - sum[i - 1][k];
                    if (s == 0) {
                        res.push_back({i - 1, 0});
                        res.push_back({j - 1, k - 1});
                        return res;
                    }
                    if (mp.find(s) != mp.end()) {
                        res.push_back({i - 1, mp[s]});
                        res.push_back({j - 1, k - 1});
                        return res;
                    }
                    mp[s] = k;
                }
            }
        }
        res.push_back({0, 0});
        res.push_back({0, 0});
        return res;
    }
};