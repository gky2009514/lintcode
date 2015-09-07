class Solution {
public:
    /**
     * @param s : A string
     * @return : A string
     */
    string reverseWords(string s) {
        if (s.length() == 0)
            return string();
        while (!stk.empty())
            stk.pop();
        int n = static_cast<int>(s.length());
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && isspace(s[j]))
                j++;
            int k = j + 1;
            while (k < n && !isspace(s[k]))
                k++;
            if (j < n)
                stk.push(s.substr(j, k - j));
            i = k;
        }
        if (stk.empty())
            return string();
        string reverse = stk.top();
        stk.pop();
        while (!stk.empty()) {
            reverse += " " + stk.top();
            stk.pop();
        }
        return reverse;
    }

private:
    stack<string> stk;
};