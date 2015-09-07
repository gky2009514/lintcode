class Solution {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        n = static_cast<int>(S.size());
        if (n <= 2)
            return 0;
        sort(S.begin(), S.end());
        int num = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int k = binaryFind(S, S[i] + S[j]);
                if (k > j)
                    num += k - j;
            }
        }
        return num;
    }

private:
    int n;
    int binaryFind(const vector<int> &S, int sum) {
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (S[mid] >= sum)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return r;
    }
};