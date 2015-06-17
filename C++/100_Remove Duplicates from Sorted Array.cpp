class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        map<int, bool> mp;
        for (auto it = nums.begin(); it != nums.end(); ) {
            if (mp.find(*it) == mp.end()) {
                mp[*it] = true;
                it++;
            }
            else
                it = nums.erase(it);
        }
        return static_cast<int>(nums.size());
    }
};