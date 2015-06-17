class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        int count = 0, num = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0)
                num = nums[i];
            if (num == nums[i])
                count++;
            else
                count--;
        }
        return num;
    }
};