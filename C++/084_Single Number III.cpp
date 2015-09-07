class Solution {
public:
    /**
     * @param A : An integer array
     * @return : Two integers
     */
    vector<int> singleNumberIII(vector<int> &A) {
        vector<int> res;
        if (A.size() == 0)
            return res;
        int a_xor_b = 0;
        for (int i = 0; i < A.size(); i++)
            a_xor_b ^= A[i];
        int mask = 1 << lastBit(a_xor_b);
        int a = 0, b = 0;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] & mask)
                a ^= A[i];
            else
                b ^= A[i];
        }
        res.push_back(a);
        res.push_back(b);
        return res;
    }

private:
    int lastBit(int x) {
        int pos = 0;
        while (true) {
            if (x & 1)
                return pos;
            x >>= 1;
            pos++;
        }
        return pos;
    }
};