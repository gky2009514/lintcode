class Solution {
public:
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> A) {
        int n = static_cast<int>(A.size());
        if (n <= 0)
            return 0;
        vector<long long> rb(n + 1, 0), nr(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            rb[i] = max(rb[i - 1], nr[i - 1] + A[i - 1]);
            nr[i] = max(rb[i - 1], nr[i - 1]);
        }
        return max(rb[n], nr[n]);
    }
};