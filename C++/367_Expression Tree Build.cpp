class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The root of expression tree
     */
    ExpressionTreeNode* build(vector<string> &expression) {
        int n = static_cast<int>(expression.size());
        if (n <= 0)
            return NULL;
        return buildRange(expression, 0, n - 1);
    }

private:
    ExpressionTreeNode* buildRange(const vector<string> &expr, int l, int r) {
        if (l > r)
            return NULL;
        deque<ExpressionTreeNode*> dq;
        deque<string> ope;
        for (int i = l; i <= r; i++) {
            if (expr[i] == "+" || expr[i] == "-" || expr[i] == "*" || expr[i] == "/") {
                ope.push_back(expr[i]);
            } else {
                ExpressionTreeNode *rt = NULL, *now = NULL;
                if (expr[i] == "(") {
                    int j = findMatch(expr, i + 1);
                    rt = buildRange(expr, i + 1, j - 1);
                    i = j;
                } else {
                    rt = new ExpressionTreeNode(expr[i]);
                }
                if (!ope.empty() && (ope.back() == "*" || ope.back() == "/")) {
                    now = new ExpressionTreeNode(ope.back());
                    ope.pop_back();
                    now->left = dq.back();
                    dq.pop_back();
                    now->right = rt;
                    rt = now;
                }
                dq.push_back(rt);
            }
        }
        while (!ope.empty()) {
            ExpressionTreeNode *lt = dq.front();
            dq.pop_front();
            ExpressionTreeNode *rt = dq.front();
            dq.pop_front();
            ExpressionTreeNode *now = new ExpressionTreeNode(ope.front());
            ope.pop_front();
            now->left = lt, now->right = rt;
            dq.push_front(now);
        }
        return dq.front();
    }

    int findMatch(const vector<string> expr, int pos) {
        stack<string> stk;
        while (pos < expr.size()) {
            if (expr[pos] == "(")
                stk.push(expr[pos]);
            if (expr[pos] == ")") {
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