class Solution {
public:
    /**
     * @param tokens The Reverse Polish Notation
     * @return the value
     */
    int evalRPN(vector<string>& tokens) {
        stack<int> ope;
        for (int i = 0; i < tokens.size(); i++) {
            if (isdigit(tokens[i][0]) || (tokens[i].length() > 1 && tokens[i][0] == '-')) {
                char *end;
                int num = static_cast<int>(strtol(tokens[i].c_str(), &end, 10));
                ope.push(num);
            } else {
                int r = ope.top();
                ope.pop();
                int l = ope.top();
                ope.pop();
                switch (tokens[i][0]) {
                    case '+': ope.push(l + r); break;
                    case '-': ope.push(l - r); break;
                    case '*': ope.push(l * r); break;
                    case '/': ope.push(l / r); break;
                    default: ope.push(0); break;
                }
            }
        }
        return ope.top();
    }
};