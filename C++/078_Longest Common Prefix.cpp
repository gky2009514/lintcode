class Solution {
public:
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() <= 0)
            return "";
        if (strs.size() == 1)
            return strs[0];
        string prefix = calPrefix(strs[0], strs[1]);
        for (int i = 2; i < strs.size(); i++)
            prefix = calPrefix(prefix, strs[i]);
        return prefix;
    }

private:
    string calPrefix(const string &a, const string &b) {
        int pos = 0;
        while (pos < a.length() && pos < b.length()) {
            if (a[pos] != b[pos])
                break;
            pos++;
        }
        return a.substr(0, pos);
    }
};