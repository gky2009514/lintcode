class Solution {
public:
    /**
     * @param source: A string
     * @param target: A string
     * @return: A string denote the minimum window
     *          Return "" if there is no such a string
     */
    string minWindow(string &source, string &target) {
        map<char, int> mp;
        int n = static_cast<int>(source.size());
        if (n == 0)
            return "";
        int m = static_cast<int>(target.size());
        if (m == 0)
            return "";
        for (int i = 0; i < m; i++)
            mp[target[i]]++;
        int l = 0, r = 0, st = -1, ed = n;
        while (r < n) {
            while (m && r < n) {
                mp[source[r]]--;
                if (mp[source[r]] >= 0)
                    m--;
                r++;
            }
            if (m && r >= n)
                break;
            while (!m && l < r) {
                if (r - l < ed - st)
                    st = l, ed = r;
                mp[source[l]]++;
                if (mp[source[l]] > 0)
                    m++;
                l++;
            }
        }
        if (st != -1)
            return source.substr(st, ed - st);
        else
            return "";
    }
};