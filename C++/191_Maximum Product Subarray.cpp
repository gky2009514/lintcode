class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int maxProduct(vector<int>& nums) {
        int max_pro = nums[0];
        int now_pos = INT_MIN, now_neg = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                now_pos = now_pos == INT_MIN ? nums[i] : now_pos * nums[i];
                now_neg = now_neg == INT_MAX ? INT_MAX : now_neg * nums[i];
            } else if (nums[i] < 0) {
                int pre_pos = now_pos;
                now_pos = now_neg == INT_MAX ? INT_MIN : now_neg * nums[i];
                now_neg = pre_pos == INT_MIN ? nums[i] : pre_pos * nums[i];
            } else {
                now_pos = INT_MIN;
                now_neg = INT_MAX;
            }
            max_pro = max(max_pro, now_pos);
            if (now_pos != INT_MAX)
                max_pro = max(max_pro, now_pos);
        }
        return max_pro;
    }
};