class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        if (nums.size() == 0)
            return;
        int l = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & 1) {
                int t = nums[++l];
                nums[l] = nums[i];
                nums[i] = t;
            }
        }
    }
};