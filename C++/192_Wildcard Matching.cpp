class Solution {
public:
    /**
    * @param s: A string
    * @param p: A string includes "?" and "*"
    * @return: A boolean
    */
    bool isMatch(const char *s, const char *p) {
        if (s == NULL)
            return p == NULL;
        if (p == NULL)
            return false;
        int n = static_cast<int>(strlen(s));
        int m = static_cast<int>(strlen(p));
        vector<bool> match(n + 1, false);
        match[0] = true;
        for (int i = 0; i < m; i++) {
            if (p[i] == '*') {
                for (int j = 1; j <= n; j++)
                    match[j] = match[j - 1] ? true : match[j];
            } else {
                for (int j = n; j >= 1; j--)
                    match[j] = match[j - 1] && (s[j - 1] == p[i] || p[i] == '?');
                match[0] = false;
            }
        }
        return match[n];
    }
};