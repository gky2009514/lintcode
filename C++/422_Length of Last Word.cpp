class Solution {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        int len = 0;
        for (int i = 0; i < s.length(); ) {
            int j = i;
            while (j < s.length() && isspace(s[j]))
                j++;
            if (j >= s.length())
                break;
            len = 0;
            while (j < s.length() && isalpha(s[j]))
                len++, j++;
            i = j;
        }
        return len;
    }
};