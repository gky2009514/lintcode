class Solution {
public:
    /**
    * @param nuts: a vector of integers
    * @param bolts: a vector of integers
    * @param compare: a instance of Comparator
    * @return: nothing
    */
    void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts, Comparator compare) {
        if (nuts.size() == 0)
            return;
        int n = static_cast<int>(nuts.size());
        quickSort(nuts, bolts, compare, 0, n - 1);
    }

private:
    int partition(vector<string> &part, const string &s, Comparator &comp, int left, int right) {
        int l = left - 1;
        for (int i = left; i <= right; i++) {
            if (comp.cmp(part[i], s) == -1 || comp.cmp(s, part[i]) == 1)
                swap(part[++l], part[i]);
        }
        for (int i = l + 1; i <= right; i++) {
            if (comp.cmp(part[i], s) == 0 || comp.cmp(s, part[i]) == 0) {
                swap(part[++l], part[i]);
                break;
            }
        }
        return l;
    }

    void quickSort(vector<string> &nuts, vector<string> &bolts, Comparator &comp, int left, int right) {
        if (right - left <= 0)
            return;
        int p = partition(bolts, nuts[left], comp, left, right);
        partition(nuts, bolts[p], comp, left, right);
        quickSort(nuts, bolts, comp, left, p - 1);
        quickSort(nuts, bolts, comp, p + 1, right);
    }
};