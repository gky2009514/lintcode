class Solution {
    /**
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        int l = static_cast<int>(A.size());
        if (l == 0 || target < A[0])
            return 0;
        if (target > A[l - 1])
            return l;
        this->target = target;
        return search(0, l - 1, A);
    }

private:
    int target;
    int search(int l, int r, vector<int> &A) {
        if (l > r)
            return l;
        int mid = l + ((r - l) >> 1);
        if (A[mid] == target)
            return mid;
        else if (A[mid] < target)
            return search(mid + 1, r, A);
        else
            return search(l, mid - 1, A);
    }
};