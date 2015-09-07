class Solution {
public:
    /**
     * @param n a number
     * @return Gray code
     */
    vector<int> grayCode(int n) {
        vector<int> gray;
        gray.push_back(0);
        for (int i = 1; i <= n; i++) {
            int m = static_cast<int>(gray.size());
            for (int j = m - 1; j >= 0; j--)
                gray.push_back(gray[j] | (1 << (i - 1)));
        }
        return gray;
    }
};