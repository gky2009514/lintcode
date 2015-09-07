class Solution {
public:
    /**
     * @param buildings: A list of lists of integers
     * @return: Find the outline of those buildings
     */
    vector<vector<int> > buildingOutline(vector<vector<int> > &buildings) {
        vector<vector<int> > res;
        int n = static_cast<int>(buildings.size());
        if (n == 0)
            return res;
        sort(buildings.begin(), buildings.end());
        vector<pair<int, int> > mg = divideBud(buildings, 0, n - 1);
        int m = static_cast<int>(mg.size());
        for (int i = 0; i < m - 1; i++) {
            if (mg[i].second == 0)
                continue;
            res.push_back(vector<int>{mg[i].first, mg[i + 1].first, mg[i].second});
        }
        return res;
    }

private:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0];
    }

    vector<pair<int, int> > divideBud(const vector<vector<int> > &bud, int l, int r) {
        vector<pair<int, int> > res;
        if (l > r)
            return res;
        if (l == r) {
            res.push_back(pair<int, int>(bud[l][0], bud[l][2]));
            res.push_back(pair<int, int>(bud[l][1], 0));
            return res;
        }
        int mid = l + ((r - l) >> 1);
        vector<pair<int, int> > ll = divideBud(bud, l, mid);
        vector<pair<int, int> > rr = divideBud(bud, mid + 1, r);
        merge(res, ll, rr);
        return res;
    }

    void merge(vector<pair<int, int> > &res, const vector<pair<int, int> > &ll,
               const vector<pair<int, int> > &rr) {
        int hl = 0, hr = 0, i = 0, j = 0, x = 0;
        while (i < ll.size() && j < rr.size()) {
            if (ll[i].first < rr[j].first) {
                x = ll[i].first;
                hl = ll[i++].second;
            } else if (rr[j].first < ll[i].first) {
                x = rr[j].first;
                hr = rr[j++].second;
            } else {
                x = ll[i].first;
                hl = ll[i++].second;
                hr = rr[j++].second;
            }
            add(res, x, max(hl, hr));
        }
        while (i < ll.size()) {
            add(res, ll[i].first, ll[i].second);
            i++;
        }
        while (j < rr.size()) {
            add(res, rr[j].first, rr[j].second);
            j++;
        }
    }

    void add(vector<pair<int, int> > &res, int l, int h) {
        int n = static_cast<int>(res.size());
        if (n == 0) {
            res.push_back(pair<int, int>(l, h));
            return;
        }
        if (res[n - 1].second == h)
            return;
        if (res[n - 1].first == l)
            res[n - 1].second = max(res[n - 1].second, h);
        res.push_back(pair<int, int>(l, h));
    }
};