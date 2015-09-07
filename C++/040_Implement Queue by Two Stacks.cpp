class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;

    Queue() {
        while (!stack1.empty())
            stack1.pop();
        while (!stack2.empty())
            stack2.pop();
    }

    void push(int element) {
        stack1.push(element);
    }

    int pop() {
        if (stack2.empty())
            shift();
        int top = stack2.top();
        stack2.pop();
        return top;
    }

    int top() {
        if (stack2.empty())
            shift();
        return stack2.top();
    }

private:
    void shift(void) {
        while (!stack1.empty()) {
            int top = stack1.top();
            stack2.push(top);
            stack1.pop();
        }
    }
};