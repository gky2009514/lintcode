class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
    int maxDiffSubArrays(vector<int> nums) {
        if (nums.size() == 0)
            return 0;
        int n = static_cast<int>(nums.size());
        int ma = INT_MIN, sum = 0;
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            ma = max(ma, sum);
            dp[i] = ma;
            sum = sum < 0 ? 0 : sum;
        }
        int mi = INT_MAX, res = INT_MIN;
        for (int i = n - 1, sum = 0; i > 0; i--) {
            sum += nums[i];
            mi = min(mi, sum);
            res = max(res, dp[i - 1] - mi);
            sum = sum > 0 ? 0 : sum;
        }
        mi = INT_MAX, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            mi = min(mi, sum);
            dp[i] = mi;
            sum = sum > 0 ? 0 : sum;
        }
        ma = INT_MIN, sum = 0;
        for (int i = n - 1; i > 0; i--) {
            sum += nums[i];
            ma = max(ma, sum);
            res = max(res, ma - dp[i - 1]);
            sum = sum < 0 ? 0 : sum;
        }
        return res;
    }
};