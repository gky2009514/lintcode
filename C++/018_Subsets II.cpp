class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsetsWithDup(const vector<int> &S) {
        sets.clear();
        choose.clear();
        nums = S;
        sort(nums.begin(), nums.end());
        pick(0);
        return sets;
    }

private:
    vector<int> choose, nums;
    vector<vector<int> > sets;

    void pick(int pos) {
        if (pos >= nums.size()) {
            sets.push_back(choose);
            return;
        }
        int ed = pos + 1;
        while (ed < nums.size() && nums[ed] == nums[pos])
            ed++;
        int up = ed - pos;
        for (int i = 0; i <= up; i++) {
            for (int j = 0; j < i; j++)
                choose.push_back(nums[pos]);
            pick(ed);
            for (int j = 0; j < i; j++)
                choose.pop_back();
        }
    }
};