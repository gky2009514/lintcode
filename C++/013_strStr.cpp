class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        if (target == NULL || source == NULL)
            return -1;
        if (target[0] == '\0')
            return 0;
        if (source[0] == '\0')
            return -1;
        int sl = static_cast<int>(strlen(source));
        int tl = static_cast<int>(strlen(target));
        vector<int> next(tl, 0);
        genNext(target, next);
        int i = 0, j = 0;
        while (i < sl && j < tl) {
            if (j == -1 || source[i] == target[j])
                i++, j++;
            else
                j = next[j];
        }
        return j >= tl ? i - j : -1;
    }

    void genNext(const char *str, vector<int> &next) {
        int len = static_cast<int>(strlen(str));
        next[0] = -1;
        int i = 0, j = -1;
        while (i < len - 1) {
            if (j == -1 || str[i] == str[j]) {
                i++, j++;
                next[i] = j;
            } else {
                j = next[j];
            }
        }
    }
};