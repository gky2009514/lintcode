class Solution {
public:
    /**
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut(vector<int> L, int k) {
        long long sum = 0;
        for (int i = 0; i < L.size(); i++)
            sum += L[i];
        if (L.size() == 0 || sum < k)
            return 0;
        int left = 0, right = -1;
        for (int i = 0; i < L.size(); i++)
            right = max(right, L[i]);
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (check(L, mid, k))
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left - 1;
    }

private:
    bool check(const vector<int> &L, const int &l, const int &k) {
        if (l == 0)
            return true;
        int num = 0;
        for (int i = 0; i < L.size(); i++)
            num += L[i] / l;
        return num >= k;
    }
};