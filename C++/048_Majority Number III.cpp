class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums, int k) {
        if (k <= 0)
            return -1;
        cnt = vector<int>(k, 0);
        vt = vector<int>(k, 0);
        for (int i = 0; i < nums.size(); i++)
            checkVote(nums[i]);
        cnt = vector<int>(k, 0);
        return findVote(nums);
    }

private:
    vector<int> cnt, vt;

    void checkVote(const int &x) {
        for (int i = 0; i < cnt.size(); i++) {
            if (cnt[i] && x == vt[i]) {
                cnt[i]++;
                return;
            }
        }
        for (int i = 0; i < cnt.size(); i++) {
            if (!cnt[i]) {
                cnt[i] = 1;
                vt[i] = x;
                return;
            }
        }
        for (int i = 0; i < cnt.size(); i++)
            cnt[i]--;
    }

    int findVote(const vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < cnt.size(); j++) {
                if (nums[i] == vt[j]) {
                    cnt[j]++;
                    break;
                }
            }
        }
        int ma = 0, pos = 0;
        for (int i = 0; i < cnt.size(); i++) {
            if (cnt[i] > ma) {
                ma = cnt[i];
                pos = i;
            }
        }
        return vt[pos];
    }
};