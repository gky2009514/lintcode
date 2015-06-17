class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermutation(vector<int> &nums) {
        if (nums.size() <= 1)
            return nums;
        int l = static_cast<int>(nums.size() - 1);
        while (l > 0 && nums[l - 1] >= nums[l])
            l--;
        if (l <= 0) {
            sort(nums.begin(), nums.end());
            return nums;
        }
        int r = l;
        while (r < nums.size() && nums[r] > nums[l - 1])
            r++;
        int t = nums[l - 1];
        nums[l - 1] = nums[r - 1];
        nums[r - 1] = t;
        reverse(nums, l, static_cast<int>(nums.size() - 1));
        return nums;
    }

private:
    void reverse(vector<int> &nums, int st, int ed) {
        int t;
        while (st < ed) {
            t = nums[st];
            nums[st] = nums[ed];
            nums[ed] = t;
            st++, ed--;
        }
    }
};