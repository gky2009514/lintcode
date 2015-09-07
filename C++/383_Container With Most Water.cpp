class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &heights) {
        int i = 0, j = static_cast<int>(heights.size()) - 1;
        int ma = 0;
        while (i < j) {
            ma = max(ma, (j - i) * min(heights[i], heights[j]));
            if (heights[i] <= heights[j])
                i++;
            else
                j--;
        }
        return ma;
    }
};