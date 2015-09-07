class Solution {
public:
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    bool wordBreak(string s, unordered_set<string> &dict) {
        if (s.length() == 0)
            return true;
        s = "*" + s;
        vector<bool>dp(s.length(), false);
        dp[0] = true;
        int max_len = getMaxLength(dict);
        for(int i = 1; i < s.length(); i++) {
            for (int j = 1; j <= max_len && j <= i; j++) {
                if (dp[i - j] && dict.find(s.substr(i - j + 1, j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length() - 1];
    }

private:
    int getMaxLength(const unordered_set<string> &dict) {
        int len = 0;
        for (auto i = dict.begin(); i != dict.end(); i++)
            len = max(len, static_cast<int>(i->length()));
        return len;
    }
};