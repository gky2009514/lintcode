class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) {
        if (nums.size() <= 0 || nums.size() < k)
            return 0;
        int left = 0, right = static_cast<int>(nums.size()) - 1;
        while (left < right) {
            int l = left - 1, senti = nums[right];
            for (int i = left; i <= right; i++) {
                if (nums[i] >= senti) {
                    int t = nums[++l];
                    nums[l] = nums[i];
                    nums[i] = t;
                }
            }
            if (l == k - 1)
                return senti;
            else if (l < k - 1)
                left = l + 1;
            else
                right = l - 1;
        }
        return nums[left];
    }
};