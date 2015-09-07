class Solution {
public:
    /**
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        if (airplanes.size() == 0)
            return 0;
        vector<fandl> p;
        for (int i = 0; i < airplanes.size(); i++) {
            p.push_back(fandl(airplanes[i].start, 1));
            p.push_back(fandl(airplanes[i].end, 0));
        }
        sort(p.begin(), p.end());
        int ma = 0, num = 0;
        for (int i = 0; i < p.size(); i++) {
            if (p[i].fly == 1)
                num++;
            else
                num--;
            ma = max(ma, num);
        }
        return ma;
    }

private:
    struct fandl {
        int pos, fly;
        fandl(int p, int f): pos(p), fly(f) {}
        bool operator < (const fandl &a) const {
            if (pos == a.pos)
                return fly < a.fly;
            return pos < a.pos;
        }
    };
};