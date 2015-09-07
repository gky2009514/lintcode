class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return a list of lists of integer
     */
    vector<vector<int> > kSumII(vector<int> A, int k, int target) {
        n = static_cast<int>(A.size());
        this->k = k, this->A = A;
        this->target = target;
        res.clear();
        choose.clear();
        dfs(0, 0, 0);
        return res;
    }

private:
    int k, n, target;
    vector<int> A, choose;
    vector<vector<int> > res;

    void dfs(int p, int num, int sum) {
        if (num == k && sum == target) {
            res.push_back(choose);
            return;
        }
        if (num > k || n - p < k - num)
            return;
        for (int i = p; i < n; i++) {
            choose.push_back(A[i]);
            dfs(i + 1, num + 1, sum + A[i]);
            choose.pop_back();
        }
    }
};