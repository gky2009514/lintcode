class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        if (x <= 0)
            return 0;
        int l = 0, r = x;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            long long s = static_cast<long long>(mid) * mid;
            if (s == x)
                return mid;
            else if (s < x)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return r;
    }
};