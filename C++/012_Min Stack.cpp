class MinStack {
public:
    MinStack() {
        while (!stk.empty())
            stk.pop();
        while (!mi.empty())
            mi.pop();
    }

    void push(int number) {
        if (mi.empty() || number <= mi.top())
            mi.push(number);
        stk.push(number);
    }

    int pop() {
        int top = stk.top();
        stk.pop();
        if (top == mi.top())
            mi.pop();
        return top;
    }

    int min() {
        return mi.top();
    }

private:
    stack<int> stk, mi;
};