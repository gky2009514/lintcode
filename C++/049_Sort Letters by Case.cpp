class Solution {
public:
    /**
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) {
        int n = static_cast<int>(letters.size());
        if (n <= 1)
            return;
        int l = -1;
        for (int i = 0; i < n; i++) {
            if (islower(letters[i]))
                swap(letters[++l], letters[i]);
        }
    }
};