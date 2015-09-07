class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        map<char, bool> mp;
        for (int i = 0; i < str.length(); i++) {
            if (mp.find(str[i]) != mp.end())
                return false;
            mp[str[i]] = true;
        }
        return true;
    }
};