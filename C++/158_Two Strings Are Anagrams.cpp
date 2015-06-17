class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        map<char, int> mp;
        for (int i = 0; i < s.length(); i++)
            mp[s[i]]++;
        for (int i = 0; i < t.length(); i++) {
            if (mp[t[i]] <= 0)
                return false;
            mp[t[i]]--;
        }
        return true;
    }
};