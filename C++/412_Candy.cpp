class Solution {
public:
    /**
     * @param ratings Children's ratings
     * @return the minimum candies you must give
     */
    int candy(vector<int>& ratings) {
        int n = static_cast<int>(ratings.size());
        if (n <= 0)
            return 0;
        vector<int> left(n, 0), right(n, 0);
        for (int i = 0; i < n; ) {
            int j = i + 1;
            while (j < n && ratings[j] > ratings[j - 1])
                j++;
            for (int k = i; k < j; k++)
                left[k] = k - i + 1;
            i = j;
        }
        for (int i = n - 1; i >= 0; ) {
            int j = i - 1;
            while (j >= 0 && ratings[j] > ratings[j + 1])
                j--;
            for (int k = i; k > j; k--)
                right[k] = i - k + 1;
            i = j;
        }
        int num = 0;
        for (int i = 0; i < n; i++)
            num += max(left[i], right[i]);
        return num;
    }
};