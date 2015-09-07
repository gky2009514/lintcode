class Solution {
public:
    /**
    * @param points an array of point
    * @return an integer
    */
    int maxPoints(vector<Point>& points) {
        if (points.size() <= 2)
            return static_cast<int>(points.size());
        map<double, int> mp;
        int ma = 0;
        for (int i = 0; i < points.size(); i++) {
            int dup = 1;
            mp.clear();
            for (int j = 0; j < points.size(); j++) {
                if (j == i)
                    continue;
                if (points[j].x == points[i].x && points[j].y == points[i].y) {
                    dup++;
                    continue;
                }
                double k = points[j].x == points[i].x ? LONG_MAX :
                    (double)(points[j].y - points[i].y) / (points[j].x - points[i].x);
                mp[k]++;
            }
            ma = max(ma, dup);
            for (auto it = mp.cbegin(); it != mp.cend(); it++)
                ma = max(ma, it->second + dup);
        }
        return ma;
    }
};