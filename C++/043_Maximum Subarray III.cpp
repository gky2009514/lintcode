class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer denote to find k non-overlapping subarrays
     * @return: An integer denote the sum of max k non-overlapping subarrays
     */
    int maxSubArray(vector<int> nums, int k) {
        if (nums.size() == 0 || k > nums.size())
            return 0;
        vector<vector<int> > dp(nums.size() + 1, vector<int>(k + 1, 0));
        for (int i = 1; i < nums.size() + 1; i++) {
            for (int j = 1; j < k + 1; j++)
                dp[i][j] = i >= j ? INT_MIN : 0;
        }
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j >= 0; j--) {
                sum += nums[j];
                for (int l = 1; l <= k && l <= j + 1; l++)
                    dp[i + 1][l] = max(dp[i + 1][l], dp[j][l - 1] + sum);
                if (sum < 0)
                    sum = 0;
            }
        }
        return dp[nums.size()][k];
    }
};