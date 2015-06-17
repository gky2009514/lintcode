class Solution {
public:
    /**
     * @param numbers: Give an array numbersbers of n integer
     * @param target: you need to find four elements that's sum of target
     * @return: Find all unique quadruplets in the array which gives the sum of
     *          zero.
     */
    vector<vector<int> > fourSum(vector<int> nums, int target) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        int i = 0, j, k, l;
        while (i < nums.size()) {
            j = i + 1;
            while (j < nums.size()) {
                int tar = target - nums[i] - nums[j];
                if (tar < (nums[j] << 1))
                    break;
                k = j + 1;
                l = static_cast<int>(nums.size()) - 1;
                while (k < l) {
                    if (nums[k] + nums[l] == tar) {
                        vector<int> t;
                        t.push_back(nums[i]);
                        t.push_back(nums[j]);
                        t.push_back(nums[k]);
                        t.push_back(nums[l]);
                        res.push_back(t);
                        do {
                            k++;
                        } while (k < l && nums[k] == nums[k - 1]);
                        do {
                            l--;
                        } while (l > k && nums[l] == nums[l + 1]);
                    } else if (nums[k] + nums[l] < tar) {
                        do {
                            k++;
                        } while (k < l && nums[k] == nums[k - 1]);
                    } else {
                        do {
                            l--;
                        } while (l > k && nums[l] == nums[l + 1]);
                    }
                }
                do {
                    j++;
                } while (j < nums.size() && nums[j] == nums[j - 1]);
            }
            do {
                i++;
            } while (i < nums.size() && nums[i] == nums[i - 1]);
        }
        return res;
    }
};