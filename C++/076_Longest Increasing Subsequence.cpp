class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        if (nums.size() == 0)
            return 0;
        int n = static_cast<int>(nums.size());
        vector<int> dp(n + 1, 0);
        int right = 0;
        dp[0] = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (nums[i] >= dp[right]) {
                dp[++right] = nums[i];
            } else {
                int l = 0, r = right;
                while (l <= r) {
                    int mid = l + ((r - l) >> 1);
                    if (nums[i] >= dp[mid])
                        l = mid + 1;
                    else
                        r = mid - 1;
                }
                dp[l] = nums[i];
            }
        }
        return right;
    }
};