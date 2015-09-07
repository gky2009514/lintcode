class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: the maximum difference
     */
    int maximumGap(vector<int> nums) {
        if (nums.size() < 2)
            return 0;
        int mi = INT_MAX, ma = 0;
        int n = static_cast<int>(nums.size());
        for (int i = 0; i < n; i++) {
            mi = min(mi, nums[i]);
            ma = max(ma, nums[i]);
        }
        int m = (ma - mi) / (n - 1);
        if (m == 0) {
            if (ma == mi)
                return 0;
            else
                m = 1;
        }
        vector<int> l(n + 1, -1), r(n + 1, -1);
        for (int i = 0; i < n; i++) {
            int p = (nums[i] - mi) / m;
            if (l[p] == -1) {
                l[p] = r[p] = nums[i];
            } else {
                l[p] = min(l[p], nums[i]);
                r[p] = max(r[p], nums[i]);
            }
        }
        int gap = 0;
        for (int i = 0; i < n; ) {
            if (r[i] == -1) {
                i++;
                continue;
            }
            int j = i + 1;
            while (j <= n && l[j] == -1)
                j++;
            if (j > n)
                break;
            gap = max(gap, l[j] - r[i]);
            i = j;
        }
        return gap;
    }
};