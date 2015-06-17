class Solution {
public:
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int tar = 0 - nums[i];
            int j = i + 1, k = static_cast<int>(nums.size()) - 1;
            while (j < k) {
                int tmp = nums[j] + nums[k];
                if (tmp == tar) {
                    vector<int> v;
                    v.push_back(nums[i]), v.push_back(nums[j]), v.push_back(nums[k]);
                    res.push_back(v);
                    do {
                        j++;
                    } while (j < nums.size() && nums[j] == nums[j - 1]);
                    do {
                        k--;
                    } while (k >= 0 && nums[k] == nums[k + 1]);
                } else if (tmp < tar) {
                    do {
                        j++;
                    } while (j < nums.size() && nums[j] == nums[j - 1]);
                } else {
                    do {
                        k--;
                    } while (k >= 0 && nums[k] == nums[k + 1]);
                }
            }
        }
        return res;
    }
};