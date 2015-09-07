class Solution{
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2
     * @return: nothing
     */
    void sortColors(vector<int> &nums) {
        int n = static_cast<int>(nums.size());
        if (n == 0)
            return;
        int l = -1, r = n;
        for (int i = 0; i < r; i++) {
            if (nums[i] == 0)
                swap(nums[++l], nums[i]);
            else if (nums[i] == 2)
                swap(nums[--r], nums[i--]);
        }
    }
};