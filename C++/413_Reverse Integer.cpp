class Solution {
public:
    /**
     * @param n the integer to be reversed
     * @return the reversed integer
     */
    int reverseInteger(int n) {
        if (n == 0)
            return 0;
        long long num = n, res = 0;
        bool sign = true;
        if (num < 0) {
            sign = false;
            num = -num;
        }
        while (num) {
            int d = num % 10;
            res = res * 10 + d;
            num /= 10;
        }
        if (!sign)
            res = -res;
        if (res > 0 && res > INT_MAX)
            return 0;
        if (res < 0 && res < INT_MIN)
            return 0;
        return static_cast<int>(res);
    }
};