class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        if (n < 0)
            return 0;
        if (n == 0)
            return k == 0 ? 1 : 0;
        int count = 0;
        long long base = 1, pre = 0;
        while (n) {
            int now = n % 10;
            int num = n / 10;
            count += num * base;
            if (now == k)
                count += pre + 1;
            else if (now > k)
                count += base;
            pre = now * base + pre;
            base *= 10;
            n /= 10;
        }
        return count;
    }
};