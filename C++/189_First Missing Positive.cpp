class Solution {
public:
    /**
     * @param A: a vector of integers
     * @return: an integer
     */
    int firstMissingPositive(vector<int> A) {
        if (A.size() == 0)
            return 1;
        for (int i = 0; i < A.size(); i++) {
            while (A[i] != i && A[i] >= 0 && A[i] < A.size()) {
                int t = A[i];
                if (A[t] == t)
                    break;
                A[i] = A[t];
                A[t] = t;
            }
        }
        for (int i = 1; i < A.size(); i++) {
            if (A[i] != i)
                return i;
        }
        return static_cast<int>(A[0] == A.size() ? A.size() + 1 : A.size());
    }
};