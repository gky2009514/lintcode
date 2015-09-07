class Solution {
public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> res;
        for (int i = 0; i < intervals.size(); i++) {
            if (res.empty()) {
                res.push_back(intervals[i]);
                continue;
            }
            Interval now = res.back();
            if (intervals[i].start > now.end) {
                res.push_back(intervals[i]);
            } else {
                now.end = max(now.end, intervals[i].end);
                res.pop_back();
                res.push_back(now);
            }
        }
        return res;
    }

private:
    static bool cmp(const Interval &a, const Interval &b) {
        if (a.start == b.start)
            return a.end < b.end;
        return a.start < b.start;
    }
};