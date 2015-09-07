class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @param s: an integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        int l = 0, r = 0, sum = 0, mi = INT_MAX;
        int n = static_cast<int>(nums.size());
        while (r < n) {
            while (r < n && sum < s)
                sum += nums[r++];
            if (sum >= s) {
                mi = min(mi, r - l);
                while (l < r && sum >= s)
                    sum -= nums[l++];
                mi = min(mi, r - l + 1);
            }
        }
        return mi == INT_MAX ? -1 : mi;
    }
};