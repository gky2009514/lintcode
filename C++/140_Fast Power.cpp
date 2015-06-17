class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        long long res = 1 % b, now = a % b;
        while (n) {
            if (n & 1)
                res = res * now % b;
            now = now * now % b;
            n >>= 1;
        }
        return static_cast<int>(res);
    }
};