class Solution {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        if (a == 0 || b == 0)
            return a == 0 ? b : a;
        int na = (a & b) << 1;
        int nb = a ^ b;
        return aplusb(na, nb);
    }
};