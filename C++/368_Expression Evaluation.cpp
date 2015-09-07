class Solution {
public:
    /**
     * @param expression: a vector of strings;
     * @return: an integer
     */
    int evaluateExpression(vector<string> &expression) {
        int n = static_cast<int>(expression.size());
        if (n == 0)
            return 0;
        return evaluateRange(expression, 0, n - 1);
    }

private:
    int evaluateRange(const vector<string> &expr, int l, int r) {
        if (l > r)
            return 0;
        deque<int> dq;
        deque<string> ope;
        for (int i = l; i <= r; i++) {
            if (expr[i] == "+" || expr[i] == "-" ||
                expr[i] == "*" || expr[i] == "/") {
                ope.push_back(expr[i]);
            } else {
                int rt;
                if (expr[i] == "(") {
                    int j = findMatch(expr, i + 1);
                    rt = evaluateRange(expr, i + 1, j - 1);
                    i = j;
                } else {
                    rt = stoi(expr[i]);
                }
                if (!ope.empty() && (ope.back() == "*" || ope.back() == "/")) {
                    int lt = dq.back();
                    dq.pop_back();
                    if (ope.back() == "*")
                        rt = lt * rt;
                    else
                        rt = lt / rt;
                    ope.pop_back();
                }
                dq.push_back(rt);
            }
        }
        int res = dq.front();
        dq.pop_front();
        while (!ope.empty()) {
            int rt = dq.front();
            dq.pop_front();
            if (ope.front() == "+")
                res += rt;
            else
                res -= rt;
            ope.pop_front();
        }
        return res;
    }

    int findMatch(const vector<string> &expr, int pos) {
        stack<string> stk;
        while (pos < expr.size()) {
            if (expr[pos] == "(") {
                stk.push(expr[pos]);
            } else if (expr[pos] == ")") {
                if (stk.empty())
                    return pos;
                else
                    stk.pop();
            }
            pos++;
        }
        return -1;
    }
};