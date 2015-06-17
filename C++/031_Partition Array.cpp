class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        int left = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < k) {
                int t = nums[++left];
                nums[left] = nums[i];
                nums[i] = t;
            }
        }
        return ++left;
    }
};