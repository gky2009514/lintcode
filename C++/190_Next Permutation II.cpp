class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: return nothing (void), do not return anything, modify nums in-place instead
     */
    void nextPermutation(vector<int> &nums) {
        if (nums.size() <= 1)
            return;
        int n = static_cast<int>(nums.size());
        int i = n - 1;
        while (i > 0 && nums[i - 1] >= nums[i])
            i--;
        if (i <= 0) {
            sort(nums.begin(), nums.end());
            return;
        }
        i--;
        int j = i + 1;
        while (j < n && nums[j] > nums[i])
            j++;
        int t = nums[i];
        nums[i] = nums[j - 1];
        nums[j - 1] = t;
        i++, j = n - 1;
        while (i < j) {
            t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
            i++, j--;
        }
    }
};