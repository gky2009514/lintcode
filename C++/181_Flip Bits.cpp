class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        return countBits(a ^ b);
    }

private:
    int countBits(int x) {
        x = (x & 0x55555555) + ((x >> 1) & 0x55555555);
        x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
        x = (x & 0x0f0f0f0f) + ((x >> 4) & 0x0f0f0f0f);
        x = (x & 0x00ff00ff) + ((x >> 8) & 0x00ff00ff);
        x = (x & 0x0000ffff) + ((x >> 16) & 0x0000ffff);
        return x;
    }
};