class Solution {
public:
    /**
    * @param grid a boolean 2D matrix
    * @return an integer
    */
    int numIslands(vector<vector<bool>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        n = static_cast<int>(grid.size());
        m = static_cast<int>(grid[0].size());
        visit = vector<vector<bool> >(n, vector<bool>(m, false));
        int num = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visit[i][j] && grid[i][j]) {
                    num++;
                    dfs(i, j, grid);
                }
            }
        }
        return num;
    }

private:
    int n, m;
    int direct[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<bool> > visit;

    void dfs(int x, int y, const vector<vector<bool> > &grid) {
        visit[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + direct[i][0];
            int ny = y + direct[i][1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m ||
                visit[nx][ny] || !grid[nx][ny])
                continue;
            dfs(nx, ny, grid);
        }
    }
};