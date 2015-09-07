class Solution {
public:
    /**
     * @param start, a string
     * @param end, a string
     * @param dict, a set of string
     * @return an integer
     */
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (start == end)
            return 0;
        map<string, bool> mp;
        queue<string> wq;
        queue<int> sq;
        wq.push(start), sq.push(1);
        mp[start] = true;
        while (!wq.empty()) {
            string frt = wq.front();
            wq.pop();
            int step = sq.front();
            sq.pop();
            if (frt == end)
                return step;
            for (int i = 0; i < frt.length(); i++) {
                char c = frt[i];
                for (char j = 'a'; j <= 'z'; j++) {
                    frt[i] = j;
                    if ((dict.find(frt) != dict.end() || frt == end) && !mp[frt]) {
                        wq.push(frt), sq.push(step + 1);
                        mp[frt] = true;
                    }
                }
                frt[i] = c;
            }
        }
        return 0;
    }
};