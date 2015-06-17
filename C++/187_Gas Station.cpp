class Solution {
public:
    /**
     * @param gas: a vector of integers
     * @param cost: a vector of integers
     * @return: an integer
     */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if (gas.size() == 0)
            return -1;
        int ct = 0, sm = 0;
        for (int i = 0; i < gas.size(); i++) {
            sm += gas[i];
            ct += cost[i];
        }
        if (sm < ct)
            return -1;
        int pos = 0;
        sm = ct = gas[0] - cost[0];
        for (int i = 1; i < gas.size(); i++) {
            sm += gas[i] - cost[i];
            if (sm < ct) {
                ct = sm;
                pos = i;
            }
        }
        return (pos + 1) % gas.size();
    }
};