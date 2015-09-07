class Solution {
public:
    void recoverRotatedSortedArray(vector<int> &nums) {
        int n = static_cast<int>(nums.size());
        if (n <= 1)
            return;
        int m = 0;
        while (m + 1 < n && nums[m] <= nums[m + 1])
            m++;
        if (m + 1 >= n)
            return;
        int i = 0, j = m;
        while (i < j)
            swap(nums[i++], nums[j--]);
        i = m + 1, j = n - 1;
        while (i < j)
            swap(nums[i++], nums[j--]);
        i = 0, j = n - 1;
        while (i < j)
            swap(nums[i++], nums[j--]);
    }
};