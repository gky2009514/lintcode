class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        this->k = k, this->n = n;
        getCom(1, res);
        return res;
    }

private:
    int k, n;
    vector<int> com;

    void getCom(int m, vector<vector<int> > &r) {
        if (com.size() >= k) {
            r.push_back(com);
            return;
        }
        if (m > n || n - m + 1 < k - com.size())
            return;
        com.push_back(m);
        getCom(m + 1, r);
        com.pop_back();
        getCom(m + 1, r);
    }
};