class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number
     *          and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> nums){
        vector<int> res;
        if (nums.size() == 0)
            return res;
        vector<pair<int, int> > sum(nums.size() + 1, pair<int, int>(0, 0));
        for (int i = 0; i < nums.size(); i++) {
            sum[i + 1].first = sum[i].first + nums[i];
            sum[i + 1].second = i + 1;
        }
        sort(sum.begin(), sum.end());
        long long mi = LONG_MAX;
        for (int i = 1; i < sum.size(); i++) {
            if (sum[i].first - sum[i - 1].first < mi) {
                mi = sum[i].first - sum[i - 1].first;
                res.clear();
                res.push_back(min(sum[i].second, sum[i - 1].second));
                res.push_back(max(sum[i].second, sum[i - 1].second) - 1);
            }
        }
        return res;
    }
};