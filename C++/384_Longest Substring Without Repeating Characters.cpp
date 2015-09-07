class Solution {
public:
    /**
     * @param s: a string
     * @return: an integer
     */
    int lengthOfLongestSubstring(string s) {
        int n = static_cast<int>(s.length());
        if (n == 0)
            return 0;
        map<char, bool> mp;
        int l = 0, r = 0, ml = 0;
        while (r < n) {
            if (mp[s[r]]) {
                while (s[l] != s[r])
                    mp[s[l++]] = false;
                mp[s[l++]] = false;
            }
            mp[s[r++]] = true;
            ml = max(ml, r - l);
        }
        return ml;
    }
};