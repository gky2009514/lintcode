class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        int max_sum = nums[0];
        int now_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            now_sum += nums[i];
            max_sum = max(max_sum, now_sum);
            now_sum = now_sum < 0 ? 0 : now_sum;
        }
        return max_sum;
    }
};