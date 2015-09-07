class Solution {
public:
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string s) {
        n = static_cast<int>(s.length());
        part = dfs(s, 0);
        for (int i = 0; i < part.size(); i++)
            reverse(part[i].begin(), part[i].end());
        return part;
    }

private:
    int n;
    vector<vector<string> > part;
    bool isPal(const string &s, int st, int ed) {
        while (st < ed) {
            if (s[st] != s[ed])
                return false;
            st++, ed--;
        }
        return true;
    }

    vector<vector<string> > dfs(const string &s, int x) {
        vector<vector<string> > res;
        if (x >= n) {
            res.push_back(vector<string>());
            return res;
        }
        for (int i = x; i < n; i++) {
            if (isPal(s, x, i)) {
                vector<vector<string> > t = dfs(s, i + 1);
                string ss = s.substr(x, i - x + 1);
                for (int j = 0; j < t.size(); j++)
                    t[j].push_back(ss);
                res.insert(res.end(), t.begin(), t.end());
            }
        }
        return res;
    }
};