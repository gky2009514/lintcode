class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        int n = static_cast<int>(prices.size());
        int i = 0, sum = 0;
        while (i < n) {
            int j = i + 1;
            while (j < n && prices[j] >= prices[j - 1])
                j++;
            if (j > i + 1)
                sum += prices[j - 1] - prices[i];
            i = j;
        }
        return sum;
    }
};