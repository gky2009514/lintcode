class Solution {
public:
    /**
    * @param pages: a vector of integers
    * @param k: an integer
    * @return: an integer
    */
    int copyBooks(vector<int> &pages, int k) {
        int mit = 0, mat = 0;
        this->n = static_cast<int>(pages.size());
        this->k = k;
        for (int i = 0; i < n; i++) {
            mit = max(mit, pages[i]);
            mat += pages[i];
        }
        while (mit <= mat) {
            int mid = mit + ((mat - mit) >> 1);
            if (check(mid, pages))
                mat = mid - 1;
            else
                mit = mid + 1;
        }
        return mat + 1;
    }

private:
    int n, k;

    bool check(int t, const vector<int> &pages) {
        int num = 0, time = 0, i = 0;
        while (i < n) {
            int j = i;
            while (j < n && time + pages[j] <= t)
                time += pages[j++];
            num++, time = 0;
            i = j;
        }
        return num <= k;
    }
};