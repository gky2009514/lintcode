class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        long long pre = LONG_MIN;
        int appear = 0;
        for (auto it = nums.begin(); it != nums.end(); ) {
            if (*it == pre) {
                appear++;
                if (appear > 2)
                    it = nums.erase(it);
                else
                    it++;
            } else {
                appear = 1;
                pre = *it;
                it++;
            }
        }
        return static_cast<int>(nums.size());
    }
};