class Solution {
public:
    Solution() {
        ways = vector<vector<int> >(N + 5, vector<int>(N + 5, 0));
        ways[0][0] = 1;
        for (int i = 1; i <= N; i++) {
            ways[i][0] = 1;
            for (int j = 1; j < i; j++)
                ways[i][j] = ways[i - 1][j - 1] + ways[i - 1][j];
            ways[i][i] = 1;
        }
    }
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        return ways[m + n - 2][m - 1];
    }

private:
    const int N = 200;
    vector<vector<int> > ways;
};