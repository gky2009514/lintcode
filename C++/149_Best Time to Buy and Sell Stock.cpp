class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        int n = static_cast<int>(prices.size());
        int ma = 0, res = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (prices[i] <= ma)
                res = max(res, ma - prices[i]);
            ma = max(ma, prices[i]);
        }
        return res;
    }
};