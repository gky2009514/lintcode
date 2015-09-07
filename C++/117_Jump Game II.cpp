class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        if (A.size() <= 1)
            return 0;
        int steps = 0, st = 0, ed = 0;
        while (st <= ed) {
            steps++;
            long long next = st;
            for (int i = st; i <= ed; i++) {
                next = max(next, (long long)i + A[i]);
                if (next >= A.size() - 1)
                    return steps;
            }
            st = ed + 1;
            ed = static_cast<int>(next);
        }
        return -1;
    }
};