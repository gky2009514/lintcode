class Solution {
public:
    /**
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
    bool isPalindrome(string& s) {
        int i = 0, j = static_cast<int>(s.length()) - 1;
        while (i < j) {
            while (i < j && !isalnum(s[i]))
                i++;
            while (i < j && !isalnum(s[j]))
                j--;
            if (i >= j)
                break;
            if (toupper(s[i++]) != toupper(s[j--]))
                return false;
        }
        return true;
    }
};