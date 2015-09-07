class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndex(vector<int>& A) {
        int n = static_cast<int>(A.size());
        if (n <= 1)
            return 1;
        long long fact[N];
        fact[0] = 1;
        for (int i = 1; i < N; i++)
            fact[i] = i * fact[i - 1];
        long long perm = 0;
        for (int i = 0; i < n; i++) {
            int num = 0;
            for (int j = i + 1; j < n; j++) {
                if (A[j] < A[i])
                    num++;
            }
            perm += fact[n - i - 1] * num;
        }
        return perm + 1;
    }

private:
    const int N = 25;
};