class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool exist(vector<vector<char> > &board, string word) {
        n = static_cast<int>(board.size());
        if (n == 0)
            return false;
        m = static_cast<int>(board[0].size());
        if (m == 0)
            return false;
        l = static_cast<int>(word.length());
        if (l == 0)
            return true;
        this->word = word;
        this->board = board;
        visit = vector<vector<bool> >(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] && dfs(0, i, j))
                    return true;
            }
        }
        return false;
    }

private:
    static const int N = 4;
    int n, m, l;
    int direct[N][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    string word;
    vector<vector<bool> > visit;
    vector<vector<char> > board;
    bool dfs(int p, int x, int y) {
        if (p >= l - 1)
            return true;
        visit[x][y] = true;
        for (int i = 0; i < N; i++) {
            int nx = x + direct[i][0];
            int ny = y + direct[i][1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m ||
                visit[nx][ny] || word[p + 1] != board[nx][ny])
                continue;
            if (dfs(p + 1, nx, ny))
                return true;
        }
        visit[x][y] = false;
        return false;
    }
};