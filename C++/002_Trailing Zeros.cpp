class Solution {
public:
    // param n : description of n
    // return: description of return
    long long trailingZeros(long long n) {
        long long num = 0;
        while (n) {
            num += n / 5;
            n /= 5;
        }
        return num;
    }
};