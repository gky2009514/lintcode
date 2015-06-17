class Solution {
    /**
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        vector<int> res(2, 0);
        res[0] = findLeft(A, target);
        res[1] = findRight(A, target);
        return res;
    }

private:
    int findLeft(const vector<int> &A, int target) {
        if (A.size() == 0)
            return -1;
        int left = 0, right = static_cast<int>(A.size() - 1);
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (A[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        return A[left] == target ? left : -1;
    }

    int findRight(const vector<int> &A, int target) {
        if (A.size() == 0)
            return -1;
        int left = 0, right = static_cast<int>(A.size() - 1);
        while (left <= right) {
            if (right - left <= 1) {
                if (A[right] == target)
                    return right;
                if (A[left] == target)
                    return left;
                return -1;
            }
            int mid = left + ((right - left) >> 1);
            if (A[mid] > target)
                right = mid - 1;
            else
                left = mid;
        }
        return -1;
    }
};