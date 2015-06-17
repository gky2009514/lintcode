class Solution {
public:
    /**
     *@param n, m: Two integer
     *@param i, j: Two bit positions
     *return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        long long mask = (((long long)1 << i) - 1) | ~(((long long)1 << (j + 1)) - 1);
        return static_cast<int>(((long long)n & mask) | ((long long)m << i));
    }
};