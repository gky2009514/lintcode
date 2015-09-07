class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        int n = static_cast<int>(heights.size());
        if (n < 3)
            return 0;
        int lm = heights[0], rm = heights[n - 1];
        int i = 1, j = n - 2, res = 0;
        while (i <= j) {
            if (heights[i] >= lm) {
                lm = heights[i++];
                continue;
            }
            if (heights[j] >= rm) {
                rm = heights[j--];
                continue;
            }
            if (lm <= rm)
                res += lm - heights[i++];
            else
                res += rm - heights[j--];
        }
        return res;
    }
};