class Solution {
    /**
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
public:
    int search(vector<int> &A, int target) {
        int left = 0, right = static_cast<int>(A.size() - 1);
        while (left <= right) {
            if (right - left <= 1) {
                if (A[left] == target)
                    return left;
                if (A[right] == target)
                    return right;
                return -1;
            }
            int mid = left + ((right - left) >> 1);
            if (A[mid] == target)
                return mid;
            if (A[left] < A[right]) {
                if (A[mid] > target)
                    right = mid - 1;
                else
                    left = mid + 1;
            } else if (A[left] > A[right]) {
                if (A[mid] > A[left]) {
                    if (target < A[mid] && target >= A[left])
                        right = mid - 1;
                    else
                        left = mid + 1;
                } else {
                    if (target > A[mid] && target <= A[right])
                        left = mid + 1;
                    else
                        right = mid - 1;
                }
            }
        }
        return -1;
    }
};