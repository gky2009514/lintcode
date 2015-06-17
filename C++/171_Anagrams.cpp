class Solution {
public:
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        map<string, vector<string> > mp;
        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            if (mp.find(s) == mp.end())
                mp[s] = vector<string>();
            mp[s].push_back(strs[i]);
        }
        vector<string> res;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (it->second.size() > 1) {
                for (int i = 0; i < it->second.size(); i++)
                    res.push_back(it->second[i]);
            }
        }
        return res;
    }
};