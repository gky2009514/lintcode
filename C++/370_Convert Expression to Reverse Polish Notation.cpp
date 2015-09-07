class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The Reverse Polish notation of this expression
     */
    vector<string> convertToRPN(vector<string> &expression) {
        int n = static_cast<int>(expression.size());
        return convertRange(expression, 0, n - 1);
    }

private:
    vector<string> convertRange(const vector<string> &expr, int l, int r) {
        vector<string> res;
        if (l > r)
            return res;
        deque<vector<string> > dq;
        deque<string> ope;
        for (int i = l; i <= r; i++) {
            if (expr[i] == "+" || expr[i] == "-" ||
                expr[i] == "*" || expr[i] == "/") {
                ope.push_back(expr[i]);
            } else {
                vector<string> lt, rt;
                if (expr[i] == "(") {
                    int j = findMatch(expr, i + 1);
                    rt = convertRange(expr, i + 1, j - 1);
                    i = j;
                } else {
                    rt.push_back(expr[i]);
                }
                if (!ope.empty() && (ope.back() == "*" || ope.back() == "/")) {
                    lt = dq.back();
                    dq.pop_back();
                    for (int j = 0; j < rt.size(); j++)
                        lt.push_back(rt[j]);
                    lt.push_back(ope.back());
                    ope.pop_back();
                    rt = lt;
                }
                dq.push_back(rt);
            }
        }
        vector<string> lt = dq.front();
        dq.pop_front();
        for (int j = 0; j < lt.size(); j++)
            res.push_back(lt[j]);
        while (!ope.empty()) {
            vector<string> rt = dq.front();
            dq.pop_front();
            for (int j = 0; j < rt.size(); j++)
                res.push_back(rt[j]);
            res.push_back(ope.front());
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