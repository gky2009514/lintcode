class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        if (string == NULL)
            return 0;
        int space_count = 0;
        for (int i = 0; i < length; i++) {
            if (string[i] == ' ')
                space_count++;
        }
        int len = length + (space_count << 1);
        string[len] = '\0';
        int i = length - 1, j = len - 1;
        while (i >= 0) {
            if (string[i] != ' ') {
                string[j--] = string[i--];
            } else {
                string[j--] = '0';
                string[j--] = '2';
                string[j--] = '%';
                i--;
            }
        }
        return len;
    }
};