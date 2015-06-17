class Solution {
public:
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    string DeleteDigits(string A, int k) {
        if (A.length() == 0)
            return "";
        int st = 0, ed;
        while (k && st < A.length()) {
            ed = getNextZero(A, st);
            if (ed >= A.length() || k < ed - st)
                break;
            k -= ed - st;
            st = ed + 1;
        }
        while (st < A.length() && A[st] == '0')
            st++;
        if (st >= A.length())
            return "0";
        string left = A.substr(st, A.length() - st);
        if (k <= 0)
            return left;
        if (k >= left.length())
            return "0";
        while (k) {
            st = 0;
            while (st + 1 < left.length() && left[st + 1] >= left[st])
                st++;
            if (st + 1 >= left.length()) {
                left = left.substr(0, left.length() - k);
                break;
            }
            left.erase(st, 1);
            k--;
        }
        return left;
    }

private:
    int getNextZero(const string &A, int st) {
        while (st < A.length() && A[st] != '0')
            st++;
        return st;
    }
};