class Solution {
public:
	/**
	* @param nums: A list of integers.
	* @return: The maximum number inside the window at each moving.
	*/
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        if (k <= 0)
            return vector<int>();
        deque<ele> dq;
        for (int i = 0; i < k; i++) {
            while (!dq.empty() && dq.back().num < nums[i])
                dq.pop_back();
            dq.push_back(ele(nums[i], i));
        }
        vector<int> ma;
        for (int i = k; i < nums.size(); i++) {
            ma.push_back(dq.front().num);
            if (i - dq.front().pos == k)
                dq.pop_front();
            while (!dq.empty() && dq.back().num < nums[i])
                dq.pop_back();
            dq.push_back(ele(nums[i], i));
        }
        ma.push_back(dq.front().num);
        return ma;
    }

private:
    struct ele {
        int num, pos;
        ele(int n, int p) : num(n), pos(p) {}
    };
};