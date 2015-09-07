class Solution {
public:
    /**
     * @param k: An integer
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(int k, vector<int> &prices) {
        n = static_cast<int>(prices.size());
        if (n <= 1 || k <= 0)
            return 0;
        if (k * 2 >= n)
            return maxPrice(prices);
        vector<int> pre(k + 1, 0), now(k + 1, 0);
        for (int i = 1; i < n; i++) {
            int diff = prices[i] - prices[i - 1];
            for (int j = k; j >= 1; j--) {
                now[j] = max(now[j] + diff, pre[j - 1] + max(diff, 0));
                pre[j] = max(pre[j], now[j]);
            }
        }
        return pre[k];
    }

private:
    int n;

    int maxPrice(const vector<int> &prices) {
        int res = 0;
        for (int i = 1; i < n; i++) {
            int diff = prices[i] - prices[i - 1];
            res += max(diff, 0);
        }
        return res;
    }
};