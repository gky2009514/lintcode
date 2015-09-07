class Solution {
public:
    /**
    * @param nums: a vector of integers
    * @return: an integer
    */
    int findMissing(vector<int> &nums) {
        long long n = nums.size();
        long long total = n * (n + 1) / 2;
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        return static_cast<int>(total - sum);
    }
};