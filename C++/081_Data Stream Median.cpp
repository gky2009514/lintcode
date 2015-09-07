class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        vector<int> median;
        if (nums.size() == 0)
            return median;
        priority_queue<int, vector<int>, greater<int> > up;
        priority_queue<int, vector<int>, less<int> > down;
        for (int i = 0; i < nums.size(); i++) {
            if (down.empty() || nums[i] <= down.top())
                down.push(nums[i]);
            else
                up.push(nums[i]);
            while (down.size() > up.size() + 1) {
                up.push(down.top());
                down.pop();
            }
            while (up.size() > down.size()) {
                down.push(up.top());
                up.pop();
            }
            median.push_back(down.top());
        }
        return median;
    }
};