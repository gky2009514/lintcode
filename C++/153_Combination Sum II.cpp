class Solution {
public:
    /**
     * @param num: Given the candidate numbers
     * @param target: Given the target number
     * @return: All the combinations that sum to target
     */
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        comb.clear();
        choose.clear();
        if (num.size() == 0)
            return comb;
        sort(num.begin(), num.end());
        this->target = target;
        pick(num, 0, 0);
        return comb;
    }

private:
    int target;
    vector<int> choose;
    vector<vector<int> > comb;

    void pick(const vector<int> &num, int sum, int pos) {
        if (sum == target) {
            comb.push_back(choose);
            return;
        }
        if (sum > target || pos >= num.size())
            return;
        int ed = pos + 1;
        while (ed < num.size() && num[ed] == num[pos])
            ed++;
        int n = ed - pos;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < i; j++)
                choose.push_back(num[pos]);
            pick(num, sum + i * num[pos], ed);
            for (int j = 0; j < i; j++)
                choose.pop_back();
        }
    }
};