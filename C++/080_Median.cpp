class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median(vector<int> &nums) {
        int n = static_cast<int>(nums.size());
        if (n == 0)
            return 0;
        k = n & 1 ? n >> 1 : (n >> 1) - 1;
        return findKth(nums, 0, n - 1);
    }

private:
    int k;
    int findKth(vector<int> &nums, int l, int r) {
        if (l >= r)
            return nums[l];
        int left = l - 1;
        for (int i = l; i < r; i++) {
            if (nums[i] < nums[r])
                swap(nums[++left], nums[i]);
        }
        swap(nums[++left], nums[r]);
        if (left < k)
            return findKth(nums, left + 1, r);
        else if (left > k)
            return findKth(nums, l, left - 1);
        else
            return nums[left];
    }
};