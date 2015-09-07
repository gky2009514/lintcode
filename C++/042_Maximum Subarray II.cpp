class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> nums) {
        if (nums.size() <= 1)
            return 0;
        int n = static_cast<int>(nums.size());
        vector<int> l_to_r(n, 0), r_to_l(n, 0);
        int ma = INT_MIN, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            ma = max(ma, sum);
            l_to_r[i] = ma;
            sum = sum < 0 ? 0 : sum;
        }
        ma = INT_MIN, sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            sum += nums[i];
            ma = max(ma, sum);
            r_to_l[i] = ma;
            sum = sum < 0 ? 0 : sum;
        }
        ma = INT_MIN;
        for (int i = 0; i < n - 1; i++)
            ma = max(ma, l_to_r[i] + r_to_l[i + 1]);
        return ma;
    }
};