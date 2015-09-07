class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    vector<string> wordSearchII(vector<vector<char> > &board, vector<string> &words) {
        if (board.size() == 0 || board[0].size() == 0 || words.size() == 0)
            return vector<string>();
        root = new trie(-1);
        for (int i = 0; i < words.size(); i++)
            insert(i, words[i]);
        n = static_cast<int>(board.size());
        m = static_cast<int>(board[0].size());
        this->words = words;
        this->board = board;
        used = vector<bool>(words.size(), false);
        visit = vector<vector<bool> >(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int pos = board[i][j] - 'a';
                if (root->next[pos]) {
                    dfs(i, j, root->next[pos]);
                    for (int k = 0; k < n; k++) {
                        for (int l = 0; l < m; l++)
                            visit[k][l] = false;
                    }
                }
            }
        }
        return find;
    }

private:
    static const int N = 26;
    static const int M = 4;
    struct trie {
        int end;
        trie *next[N];
        trie(int e): end(e) {
            for (int i = 0; i < N; i++)
                next[i] = NULL;
        }
    };
    int n, m;
    int direct[M][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    trie* root;
    vector<bool> used;
    vector<string> find, words;
    vector<vector<char> > board;
    vector<vector<bool> > visit;

    void insert(int index, string word) {
        trie *now = root;
        for (int i = 0; i < word.length(); i++) {
            int pos = word[i] - 'a';
            if (now->next[pos] == NULL)
                now->next[pos] = new trie(-1);
            now = now->next[pos];
        }
        now->end = index;
    }

    void dfs(int x, int y, trie *now) {
        visit[x][y] = true;
        if (now->end != -1 && !used[now->end]) {
            used[now->end] = true;
            find.push_back(words[now->end]);
        }
        for (int i = 0; i < M; i++) {
            int nx = x + direct[i][0];
            int ny = y + direct[i][1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            int pos = board[nx][ny] - 'a';
            if (visit[nx][ny] || !now->next[pos])
                continue;
            dfs(nx, ny, now->next[pos]);
        }
        visit[x][y] = false;
    }
};