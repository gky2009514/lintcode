class Solution {
    /**
     * param A : an integer ratated sorted array and duplicates are allowed
     * param target :  an integer to be search
     * return : a boolean
     */
public:
    bool search(vector<int> &A, int target) {
        if (A.size() == 0)
            return false;
        int left = 0, right = static_cast<int>(A.size() - 1);
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (A[mid] == target || A[left] == target || A[right] == target)
                return true;
            while (left < mid && A[left + 1] == A[left])
                left++;
            left++;
            while (right > mid && A[right - 1] == A[right])
                right--;
            right--;
            if (right - left <= 1) {
                if (A[left] == target || A[right] == target)
                    return true;
                return false;
            }
            if (A[left] < A[right]) {
                if (A[mid] > target)
                    right = mid - 1;
                else
                    left = mid + 1;
            } else {
                if (A[mid] >= left) {
                    if (target > A[mid] || target <= A[right])
                        left = mid + 1;
                    else
                        right = mid - 1;
                } else {
                    if (target > A[mid] && target <= A[right])
                        left = mid + 1;
                    else
                        right = mid - 1;
                }
            }
        }
        return false;
    }
};