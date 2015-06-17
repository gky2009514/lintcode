class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        if (A.size() <= 1)
            return true;
        vector<bool> reach(A.size(), false);
        reach[A.size() - 1] = true;
        for (int i = static_cast<int>(A.size() - 2); i >= 0; i--) {
            if (A[i] + i >= A.size() - 1)
                reach[i] = true;
            else {
                int j = 0;
                for (j = 0; j <= A[i]; j++) {
                    if (reach[i + j]) {
                        reach[i] = true;
                        break;
                    }
                }
                if (j > A[i])
                    reach[i] = false;
            }
        }
        return reach[0];
    }
};