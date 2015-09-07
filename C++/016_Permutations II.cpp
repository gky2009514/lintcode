class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of unique permutations.
     */
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        vector<vector<int> > perm;
        if (nums.size() == 0)
            return perm;
        sort(nums.begin(), nums.end());
        do {
            perm.push_back(nums);
        } while (next_perm(nums));
        return perm;
    }

private:
    bool next_perm(vector<int> &nums) {
        int st = static_cast<int>(nums.size()) - 1;
        while (st > 0 && nums[st] <= nums[st - 1])
            st--;
        if (st == 0)
            return false;
        st--;
        int ed = st + 1;
        while (ed < nums.size() && nums[ed] > nums[st])
            ed++;
        ed--;
        int t = nums[st];
        nums[st] = nums[ed];
        nums[ed] = t;
        int i = st + 1, j = static_cast<int>(nums.size()) - 1;
        while (i < j) {
            t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
            i++, j--;
        }
        return true;
    }
};