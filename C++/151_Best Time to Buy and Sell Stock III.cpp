class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        int n = static_cast<int>(prices.size());
        vector<int> sell(n + 1, 0);
        int ma = 0;
        for (int i = n - 1; i >= 0; i--) {
            sell[i] = max(ma - prices[i], sell[i + 1]);
            ma = max(ma, prices[i]);
        }
        int mi = INT_MAX, res = 0;
        for (int i = 0; i < n; i++) {
            if (prices[i] > mi)
                res = max(res, sell[i + 1] + prices[i] - mi);
            mi = min(mi, prices[i]);
        }
        return res;
    }
};