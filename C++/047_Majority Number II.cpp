class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
    int majorityNumber(vector<int> nums) {
        if (nums.size() <= 2)
            return -1;
        int cnt1 = 0, cnt2 = 0;
        int vt1 = 0, vt2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (cnt1 && nums[i] == vt1)
                cnt1++;
            else if (cnt2 && nums[i] == vt2)
                cnt2++;
            else if (!cnt1) {
                cnt1 = 1;
                vt1 = nums[i];
            } else if (!cnt2) {
                cnt2 = 1;
                vt2 = nums[i];
            } else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == vt1)
                cnt1++;
            else if (nums[i] == vt2)
                cnt2++;
        }
        return cnt1 > cnt2 ? vt1 : vt2;
    }
};