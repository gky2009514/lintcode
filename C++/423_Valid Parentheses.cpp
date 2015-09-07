class Solution {
public:
    /**
     * @param s A string
     * @return whether the string is a valid parentheses
     */
    bool isValidParentheses(string& s) {
        stack<char> bracket;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                bracket.push(s[i]);
                continue;
            }
            if (bracket.empty())
                return false;
            if (s[i] == ')' && bracket.top() != '(')
                return false;
            if (s[i] == ']' && bracket.top() != '[')
                return false;
            if (s[i] == '}' && bracket.top() != '{')
                return false;
            bracket.pop();
        }
        return bracket.empty();
    }
};