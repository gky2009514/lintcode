class Solution {
public:
    /**
     * @param s: A string
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        n = static_cast<int>(strlen(s));
        m = static_cast<int>(strlen(p));
        if (s == 0)
            return p == 0;
        if (p == 0)
            return false;
        this->s = s, this->p = p;
        match = vector<vector<int> >(n, vector<int>(m, -1));
        return dfsMatch(0, 0);
    }

private:
    int n, m;
    const char *s, *p;
    vector<vector<int> > match;

    bool dfsMatch(int x, int y) {
        if (x >= n)
            return y >= m;
        if (y >= m)
            return false;
        if (match[x][y] != -1)
            return match[x][y];
        if (y + 1 < m && p[y + 1] == '*') {
            if (dfsMatch(x, y + 2)) {
                match[x][y] = 1;
                return 1;
            }
            if (p[y] == '.') {
                for (int i = n; i > x; i--) {
                    if (dfsMatch(i, y + 2)) {
                        match[x][y] = 1;
                        return 1;
                    }
                }
                match[x][y] = 0;
            } else {
                for (int i = x; i < n && s[i] == p[y]; i++) {
                    if (dfsMatch(i + 1, y + 2)) {
                        match[x][y] = 1;
                        return 1;
                    }
                }
                match[x][y] = 0;
            }
        } else {
            if ((s[x] == p[y] || p[y] == '.') && dfsMatch(x + 1, y + 1))
                match[x][y] = 1;
            else
                match[x][y] = 0;
        }
        return match[x][y];
    }
};