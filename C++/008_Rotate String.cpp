class Solution {
public:
    /**
     * param A: A string
     * param offset: Rotate string with offset.
     * return: Rotated string.
     */
    string rotateString(string A, int offset) {
        if (A.length() == 0)
            return A;
        int n = static_cast<int>(A.length());
        offset %= n;
        swapPos(A, 0, n - 1);
        swapPos(A, 0, offset - 1);
        swapPos(A, offset, n - 1);
        return A;
    }

private:
    void swapPos(string &s, int st, int ed) {
        while (st < ed) {
            char c = s[st];
            s[st] = s[ed];
            s[ed] = c;
            st++, ed--;
        }
    }
};