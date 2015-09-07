class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        if (nums.size() == 0)
            return 0;
        int mi = INT_MAX, sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            mi = min(mi, sum);
            if (sum > 0)
                sum = 0;
        }
        return mi;
    }
};