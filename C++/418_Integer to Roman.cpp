class Solution {
public:
    /**
     * @param n The integer
     * @return Roman representation
     */
    string intToRoman(int n) {
        string s = "";
        for (int i = 0; i < N; i++) {
            while (n >= values[i]) {
                n -= values[i];
                s.append(numerals[i]);
            }
        }
        return s;
    }

private:
    static const int N = 13;
    int values[N] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    string numerals[N] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
};