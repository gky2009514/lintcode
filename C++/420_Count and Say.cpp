class Solution {
public:
    /**
     * @param n the nth
     * @return the nth sequence
     */
    string countAndSay(int n) {
        string s = "1", t;
        if (n <= 1)
            return s;
        for (int i = 2; i <= n; i++) {
            t = "";
            for (int j = 0; j < s.length(); ) {
                int k = j + 1;
                while (k < s.length() && s[k] == s[k - 1])
                    k++;
                addStr(t, k - j, s[j]);
                j = k;
            }
            s = t;
        }
        return s;
    }

private:
    void addStr(string &s, int num, char c) {
        char digit[10];
        int p = 0;
        while (num) {
            digit[p++] = num % 10 + '0';
            num /= 10;
        }
        for (int i = p - 1; i >= 0; i--)
            s += string(1, digit[i]);
        s += string(1, c);
    }
};