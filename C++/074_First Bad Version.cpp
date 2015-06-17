/**
 * class VersionControl {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use VersionControl::isBadVersion(k) to judge whether
 * the kth code version is bad or not.
 */
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        if (n <= 0)
            return n;
        int left = 1, right = n;
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (!VersionControl::isBadVersion(mid))
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};