class Solution {
public:
    /**
    * @param dictionary: a vector of strings
    * @return: a vector of strings
    */
    vector<string> longestWords(vector<string> &dictionary) {
        vector<string> longest;
        for (int i = 0; i < dictionary.size(); i++) {
            if (longest.empty()) {
                longest.push_back(dictionary[i]);
                continue;
            }
            if (dictionary[i].length() > longest[0].length()) {
                longest.clear();
                longest.push_back(dictionary[i]);
            } else if (dictionary[i].length() == longest[0].length()) {
                longest.push_back(dictionary[i]);
            }
        }
        return longest;
    }
};