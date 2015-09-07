class Solution{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */
    void sortColors2(vector<int> &colors, int k) {
        int n = static_cast<int>(colors.size());
        if (n == 0 || k <= 1)
            return;
        for (int i = 1, l = -1; i < k; i++) {
            for (int j = l + 1; j < n; j++) {
                if (colors[j] == i)
                    swap(colors[++l], colors[j]);
            }
        }
    }
};