class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return an integer
     */
    int longestConsecutive(vector<int> &num) {
        if (num.size() == 0)
            return 0;
        map<int, bool> mp;
        for (int i = 0; i < num.size(); i++)
            mp[num[i]] = true;
        long long pre = LONG_LONG_MIN;
        int ma = 0, len = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (it->first == pre + 1)
                len++;
            else
                len = 1;
            pre = it->first;
            ma = max(ma, len);
        }
        return ma;
    }
};