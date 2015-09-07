class Solution {
public:
    /**
     * @param s input string
     * @return the longest palindromic substring
     */
    string longestPalindrome(string& s) {
        int n = static_cast<int>(s.length());
        if (n <= 1)
            return s;
        char str[(n << 1) + 2];
        int m = 0;
        str[m++] = '*';
        for (int i = 0; i < n; i++) {
            str[m++] = s[i];
            str[m++] = '*';
        }
        str[m] = '\0';
        vector<int> dp(m, 0);
        dp[0] = 1, dp[1] = 3;
        int nc = 1, nr = 2;
        int st = 0, ed = 2, ma = 3;
        for (int i = 2; i < m; i++) {
            dp[i] = min(dp[(nc << 1) - i], dp[nc] - (i - nc) * 2);
            dp[i] = dp[i] <= 0 ? 1 : dp[i];
            int j = i - (dp[i] + 1) / 2;
            int k = i + (dp[i] + 1) / 2;
            while (j >= 0 && k < m && str[j] == str[k]) {
                dp[i] += 2;
                j--, k++;
            }
            if (i + dp[i] / 2 > nr) {
                nc = i;
                nr = i + dp[i] / 2;
            }
            if (dp[i] > ma) {
                ma = dp[i];
                st = j + 1, ed = k - 1;
            }
        }
        string res = "";
        for (int i = st; i <= ed; i++) {
            if (str[i] == '*')
                continue;
            res.append(string(1, str[i]));
        }
        return res;
    }
};