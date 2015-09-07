class Solution {
public:
    /**
    * @param nums: A list of integers.
    * @return: The median of the element inside the window at each moving
    */
    vector<int> medianSlidingWindow(vector<int> &nums, int k) {
        if (nums.size() <= 0 || k <= 0)
            return vector<int>();
        multiset<int, less<int> > mis;
        multiset<int, greater<int> > mas;
        vector<int> median;
        for (int i = 0; i < nums.size(); i++) {
            if (i >= k) {
                median.push_back(*mas.cbegin());
                if (mas.find(nums[i - k]) != mas.cend())
                    mas.erase(mas.find(nums[i - k]));
                else
                    mis.erase(mis.find(nums[i - k]));
            }
            if (!mas.empty() && nums[i] <= *mas.cbegin())
                mas.insert(nums[i]);
            else
                mis.insert(nums[i]);
            if (mas.size() > mis.size() + 1) {
                mis.insert(*mas.cbegin());
                mas.erase(mas.cbegin());
            } else if (mis.size() > mas.size()) {
                mas.insert(*mis.cbegin());
                mis.erase(mis.cbegin());
            }
        }
        median.push_back(*mas.cbegin());
        return median;
    }
};