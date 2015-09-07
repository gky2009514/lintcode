class Solution {
public:
    /**
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res;
        bool insert = false;
        for (int i = 0; i < intervals.size(); i++) {
            if (insert) {
                res.push_back(intervals[i]);
                continue;
            }
            if (intervals[i].end < newInterval.start) {
                res.push_back(intervals[i]);
            } else if (newInterval.end < intervals[i].start) {
                res.push_back(newInterval);
                res.push_back(intervals[i]);
                insert = true;
            } else {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }
        }
        if (!insert)
            res.push_back(newInterval);
        return res;
    }
};