class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndexII(vector<int>& A) {
        fact[0] = 1;
        for (int i = 1; i < N; i++)
            fact[i] = i * fact[i - 1];
        int n = static_cast<int>(A.size());
        if (n <= 1)
            return 1;
        long long index = 0;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp.clear(), mp[A[i]] = 1;
            for (int j = i + 1; j < n; j++)
                mp[A[j]]++;
            for (auto it = mp.begin(); it != mp.end(); it++) {
                if (it->first < A[i]) {
                    mp[it->first]--;
                    long long t = fact[n - i - 1];
                    for (auto jt = mp.begin(); jt != mp.end(); jt++)
                        t /= fact[jt->second];
                    index += t;
                    mp[it->first]++;
                }
            }
        }
        return index + 1;
    }

private:
    static const int N = 25;
    long long fact[N];
};