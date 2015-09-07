class Solution {
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    vector<int> numbersByRecursion(int n) {
        this->n = n;
        res.clear();
        dfs(0, 0);
        return res;
    }

private:
    int n;
    vector<int> res;

    void dfs(int num, int pos) {
        if (pos >= n) {
            if (num)
                res.push_back(num);
            return;
        }
        for (int i = 0; i <= 9; i++)
            dfs(num * 10 + i, pos + 1);
    }
};