class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &height) {
        height.push_back(0);
        int ma = 0;
        for (int i = 0; i < height.size(); i++) {
            while (!stk.empty() && height[i] < height[stk.top()]) {
                int top = stk.top();
                stk.pop();
                int area = stk.empty() ? height[top] * i :
                                            height[top] * (i - stk.top() - 1);
                ma = max(ma, area);
            }
            stk.push(i);
        }
        return ma;
    }

private:
    stack<int> stk;
};