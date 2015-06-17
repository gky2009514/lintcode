class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true
     *           else return false
     */
    bool compareStrings(string A, string B) {
        if (A.length() < B.length())
            return false;
        const int N = 26;
        int num[N];
        memset(num, 0, N * sizeof(int));
        for (int i = 0; i < A.length(); i++)
            num[A[i] - 'A']++;
        for (int i = 0; i < B.length(); i++) {
            num[B[i] - 'A']--;
            if (num[B[i] - 'A'] < 0)
                return false;
        }
        return true;
    }
};