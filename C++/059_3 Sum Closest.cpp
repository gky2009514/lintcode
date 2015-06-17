class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0, dist = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int tar = target - nums[i];
            int j = i + 1, k = static_cast<int>(nums.size()) - 1;
            while (j < k) {
                int tmp = nums[j] + nums[k];
                if (abs(tmp - tar) < dist) {
                    dist = abs(tmp - tar);
                    res = tmp + nums[i];
                }
                if (tmp < tar)
                    j++;
                else
                    k--;
            }
        }
        return res;
    }
};