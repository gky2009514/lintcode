class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> res;
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]] = i;
        for (int i = 0; i < nums.size(); i++) {
            int j = target - nums[i];
            if (mp.find(j) != mp.end() && mp[j] > i) {
                res.push_back(i + 1), res.push_back(mp[j] + 1);
                break;
            }
        }
        if (res.size() == 0) {
            int half = target >> 1;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == half)
                    res.push_back(i + 1);
            }
        }
        return res;
    }
};