class Solution {
public:
    /**
     * @param start, a string
     * @param end, a string
     * @param dict, a set of string
     * @return a list of lists of string
     */
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        chain.clear();
        ladders.clear();
        if (start == end) {
            chain.push_back(start);
            ladders.push_back(chain);
            return ladders;
        }
        this->start = start, this->end = end;
        shortest = findShortest(dict);
        if (shortest == 0)
            return ladders;
        chain.push_back(end);
        getShortest(shortest, end, dict);
        return ladders;
    }

private:
    int shortest;
    string start, end;
    map<string, int> mp;
    vector<string> chain;
    vector<vector<string> > ladders;

    int findShortest(const unordered_set<string> &dict) {
        mp.clear();
        queue<string> wq;
        mp[start] = 0;
        wq.push(start);
        while (!wq.empty()) {
            string frt = wq.front();
            wq.pop();
            if (frt == end)
                return mp[frt];
            for (int i = 0; i < frt.length(); i++) {
                char c = frt[i];
                int step = mp[frt];
                for (char j = 'a'; j <= 'z'; j++) {
                    frt[i] = j;
                    if ((frt == end || dict.find(frt) != dict.end()) &&
                        mp.find(frt) == mp.end()) {
                        mp[frt] = step + 1;
                        wq.push(frt);
                    }
                }
                frt[i] = c;
            }
        }
        return 0;
    }

    void getShortest(int step, string now, const unordered_set<string> &dict) {
        if (now == start) {
            reverse(chain.begin(), chain.end());
            ladders.push_back(chain);
            reverse(chain.begin(), chain.end());
            return;
        }
        if (step <= 0)
            return;
        for (int i = 0; i < now.length(); i++) {
            char c = now[i];
            for (char j = 'a'; j <= 'z'; j++) {
                if (j == c)
                    continue;
                now[i] = j;
                if ((now == start || dict.find(now) != dict.end()) &&
                    mp[now] == step - 1) {
                    chain.push_back(now);
                    getShortest(step - 1, now, dict);
                    chain.pop_back();
                }
            }
            now[i] = c;
        }
    }
};