class Solution {
public:
    /**
     * @param s the string that represents a number
     * @return whether the string is a valid number
     */
    bool isNumber(string& s) {
        int state = 0;
        for (int i = 0; i < s.length(); i++) {
            type now = INVALID;
            if (isspace(s[i]))
                now = SPACE;
            else if (s[i] == '+' || s[i] == '-')
                now = SIGN;
            else if (isdigit(s[i]))
                now = DIGIT;
            else if (s[i] == '.')
                now = DOT;
            else if (s[i] == 'e' || s[i] == 'E')
                now = EXPONENT;
            state = trans[state][now];
            if (state == -1)
                return false;
        }
        return state == 1 || state == 4 || state == 7 || state == 8;
    }

private:
    static const int N = 6;
    enum type {
        INVALID, SPACE, SIGN, DIGIT, DOT, EXPONENT
    };
    int trans[9][N] = {
        {-1,  0,  3,  1,  2, -1},
        {-1,  8, -1,  1,  4,  5},
        {-1, -1, -1,  4, -1, -1},
        {-1, -1, -1,  1,  2, -1},
        {-1,  8, -1,  4, -1,  5},
        {-1, -1,  6,  7, -1, -1},
        {-1, -1, -1,  7, -1, -1},
        {-1,  8, -1,  7, -1, -1},
        {-1,  8, -1, -1, -1, -1},
    };
};