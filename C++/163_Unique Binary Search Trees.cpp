class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        if (n <= 1)
            return 1;
        long long num = 1;
        for (int i = 2; i <= n; i++)
            num = num * ((i << 2) - 2) / (i + 1);
        return static_cast<int>(num);
    }
};