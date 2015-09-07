class Solution {
public:
    /**
     * @param dividend the dividend
     * @param divisor the divisor
     * @return the result
     */
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if (dividend == 0 || divisor == 1)
            return dividend;
        long long ded = dividend, dvr = divisor;
        bool sign = (ded > 0 && dvr > 0) || (ded < 0 && dvr < 0);
        ded = abs(ded), dvr = abs(dvr);
        if (ded < dvr)
            return 0;
        long long res = 0, num = 1;
        while (dvr <= ded) {
            dvr <<= 1;
            num <<= 1;
        }
        dvr >>= 1;
        num >>= 1;
        while (num >= 1) {
            if (ded >= dvr) {
                ded -= dvr;
                res += num;
            }
            dvr >>= 1;
            num >>= 1;
        }
        res = sign ? res : -res;
        return static_cast<int>(res);
    }
};