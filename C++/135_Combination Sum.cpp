class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        res.clear();
        if (candidates.size() == 0)
            return res;
        this->target = target;
        choose.clear();
        sort(candidates.begin(), candidates.end());
        comSum(candidates, 0, 0);
        return res;
    }

private:
    int target;
    vector<int> choose;
    vector<vector<int> > res;

    void comSum(vector<int> &candi, int now, int p) {
        if (now == target) {
            res.push_back(choose);
            return;
        }
        if (now > target || p >= candi.size())
            return;
        int up = (target - now) / candi[p];
        for (int i = 1; i <= up; i++) {
            choose.push_back(candi[p]);
            comSum(candi, now + i * candi[p], p + 1);
        }
        for (int i = 1; i <= up; i++)
            choose.pop_back();
        comSum(candi, now, p + 1);
    }
};