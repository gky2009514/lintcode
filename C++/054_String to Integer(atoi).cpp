class Solution {
public:
    /**
     * @param str: A string
     * @return An integer
     */
    int atoi(string str) {
        int i = 0;
        while (i < str.length() && isspace(str[i]))
            i++;
        if (i >= str.length())
            return 0;
        bool neg = false;
        if (str[i] == '-' || str[i] == '+') {
            neg = str[i] == '-' ? true : false;
            i++;
        }
        long long res = 0;
        while (i < str.length() && isdigit(str[i])) {
            res = res * 10 + str[i++] - '0';
            if (neg && -res < INT_MIN)
                return INT_MIN;
            if (!neg && res > INT_MAX)
                return INT_MAX;
        }
        return neg ? static_cast<int>(-res) : static_cast<int>(res);
    }
};