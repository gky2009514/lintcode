class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0.
     */
    int binarySearch(vector<int> &array, int target) {
        int l = 0, r = static_cast<int>(array.size()) - 1;
        this->target = target;
        return search(array, l, r);
    }

private:
    int target;
    int search(vector<int> &array, int l, int r) {
        if (l > r)
            return -1;
        if (l == r)
            return array[l] == target ? l : -1;
        if (r - l == 1) {
            if (array[l] == target)
                return l;
            if (array[r] == target)
                return r;
            return -1;
        }
        int mid = l + ((r - l) >> 1);
        if (array[mid] == target)
            return search(array, l, mid);
        else if (array[mid] < target)
            return search(array, mid + 1, r);
        else
            return search(array, l, mid - 1);
    }
};