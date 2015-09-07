class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int> > permute(vector<int> nums) {
        vector<vector<int> > perm;
        if (nums.size() == 0)
            return perm;
        sort(nums.begin(), nums.end());
        do {
            perm.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return perm;
    }
};