class Solution {
public:
    /**
     * @param s : A string
     * @return : The length of the longest substring
     *           that contains at most k distinct characters.
     */
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = static_cast<int>(s.length());
        if (n == 0 || k <= 0)
            return 0;
        int l = 0, r = 0, num = 0, ma = 0;
        map<char, int> mp;
        while (r < n) {
            if (!mp[s[r]]) {
                while (num >= k) {
                    mp[s[l]]--;
                    if (!mp[s[l++]])
                        num--;
                }
                num++;
            }
            mp[s[r++]]++;
            ma = max(ma, r - l);
        }
        return ma;
    }
};