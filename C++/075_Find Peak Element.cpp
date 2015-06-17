class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        int left = 0, right = static_cast<int>(A.size() - 1);
        while (left <= right) {
            if (right - left <= 1)
                return A[left] >= A[right] ? left : right;
            int mid = left + ((right - left) >> 1);
            if (A[mid] >= A[mid - 1] && A[mid] >= A[mid + 1])
                return mid;
            if (A[mid] >= A[mid - 1])
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};