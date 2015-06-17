class Solution {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        if (num.size() == 0)
            return 0;
        int left = 0, right = static_cast<int>(num.size()) - 1;
        while (left < right) {
            if (num[left] < num[right])
                return num[left];
            if (right - left == 1)
                return min(num[left], num[right]);
            int mid = left + ((right - left) >> 1);
            if (num[mid] >= num[left])
                left = mid + 1;
            else
                right = mid;
        }
        return num[left];
    }
};