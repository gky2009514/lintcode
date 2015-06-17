class Solution {
public:
    /**
     * @param num: the rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        if (num.size() == 0)
            return -1;
        int left = 0, right = static_cast<int>(num.size() - 1);
        while (left <= right) {
            if (right - left <= 1)
                return min(num[left], num[right]);
            if (num[left] < num[right])
                return num[left];
            int mid = left + ((right - left) >> 1);
            if (num[mid] < num[right]) {
                right = mid;
            } else if (num[mid] > num[right]) {
                left = mid + 1;
            } else {
                while (left < mid && num[left + 1] == num[left])
                    left++;
                if (left < mid)
                    right = mid;
            }
        }
        return -1;
    }
};