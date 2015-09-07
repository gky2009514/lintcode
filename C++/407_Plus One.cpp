class Solution {
public:
    /**
     * @param digits a number represented as an array of digits
     * @return the result
     */
    vector<int> plusOne(vector<int>& digits) {
        int n = static_cast<int>(digits.size());
        if (n == 0) {
            digits.push_back(1);
            return digits;
        }
        int sum, carry = 1;
        for (int i = n - 1; i >= 0; i--) {
            sum = digits[i] + carry;
            carry = sum / 10;
            digits[i] = sum % 10;
        }
        if (carry)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};