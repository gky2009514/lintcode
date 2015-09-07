class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's previous permuation
     */
    vector<int> previousPermuation(vector<int> &nums) {
        int n = static_cast<int>(nums.size());
        if (n <= 1)
            return nums;
        int p = n - 1;
        while (p - 1 >= 0 && nums[p - 1] <= nums[p])
            p--;
        if (p == 0) {
            reverse(nums.begin(), nums.end());
            return nums;
        }
        int s = p;
        while (s < n && nums[s] < nums[p - 1])
            s++;
        swap(nums[p - 1], nums[s - 1]);
        int i = p, j = n - 1;
        while (i < j)
            swap(nums[i++], nums[j--]);
        return nums;
    }
};