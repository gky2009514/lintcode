class Solution {
public:
    /**
     * @param a a number
     * @param b a number
     * @return the result
     */
    string addBinary(string& a, string& b) {
        int n = static_cast<int>(a.length());
        int m = static_cast<int>(b.length());
        int i = n - 1, j = m - 1;
        int tmp, carry = 0;
        string sum = "";
        while (i >= 0 && j >= 0) {
            tmp = a[i--] - '0' + b[j--] - '0' + carry;
            carry = tmp / 2;
            sum = string(1, tmp % 2 + '0') + sum;
        }
        while (i >= 0) {
            tmp = a[i--] - '0' + carry;
            carry = tmp / 2;
            sum = string(1, tmp % 2 + '0') + sum;
        }
        while (j >= 0) {
            tmp = b[j--] - '0' + carry;
            carry = tmp / 2;
            sum = string(1, tmp % 2 + '0') + sum;
        }
        if (carry)
            sum = string(1, '1') + sum;
        return sum;
    }
};