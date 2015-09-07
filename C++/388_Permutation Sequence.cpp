class Solution {
public:
    /**
     * @param n: n
     * @param k: the kth permutation
     * @return: return the k-th permutation
     */
    string getPermutation(int n, int k) {
        vector<int> fact(N, 0);
        fact[0] = 1;
        for (int i = 1; i < N; i++)
            fact[i] = i * fact[i - 1];
        k -= 1;
        string res(n, '0');
        vector<bool> used(N, false);
        for (int i = 1; i <= n; i++) {
            int t = k / fact[n - i];
            k -= t * fact[n - i];
            int j, l;
            for (j = 1, l = 0; ; j++) {
                if (!used[j])
                    l++;
                if (l > t)
                    break;
            }
            used[j] = true;
            res[i - 1] += j;
        }
        return res;
    };

private:
    const int N = 10;
};