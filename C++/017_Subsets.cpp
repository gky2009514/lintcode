class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsets(vector<int> &nums) {
        sets.clear();
        choose.clear();
        sort(nums.begin(), nums.end());
        pick(0, nums);
        return sets;
    }

private:
    vector<int> choose;
    vector<vector<int> > sets;

    void pick(int pos, const vector<int> &nums) {
        if (pos >= nums.size()) {
            sets.push_back(choose);
            return;
        }
        choose.push_back(nums[pos]);
        pick(pos + 1, nums);
        choose.pop_back();
        pick(pos + 1, nums);
    }
};