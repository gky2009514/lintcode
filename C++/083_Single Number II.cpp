class Solution {
public:
    /**
     * @param A : An integer array
     * @return : An integer
     */
    int singleNumberII(vector<int> &A) {
        if (A.size() == 0)
            return 0;
        int ones = 0, twos = 0;
        for (int i = 0; i < A.size(); i++) {
            int carry = twos & A[i];
            twos = (twos ^ ones & A[i]) & ~carry;
            ones = ones ^ (A[i] & ~carry);
        }
        return ones;
    }
};