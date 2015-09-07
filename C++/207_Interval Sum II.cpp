class Solution {
public:
    /* you may need to use some attributes here */
    /**
     * @param A: An integer vector
     */
    Solution(vector<int> A) {
        n = static_cast<int>(A.size());
        this->A = A;
        root = buildTree(0, n - 1);
    }

    /**
     * @param start, end: Indices
     * @return: The sum from start to end
     */
    long long query(int start, int end) {
        return getSum(root, start, end);
    }

    /**
     * @param index, value: modify A[index] to value.
     */
    void modify(int index, int value) {
        update(root, index, value);
    }

private:
    struct Segment {
        int st, ed;
        long long sum;
        Segment *left, *right;
        Segment(int s, int e, long long m) {
            st = s, ed = e, sum = m;
            left = right = NULL;
        }
    };
    int n;
    vector<int> A;
    Segment *root;

    Segment *buildTree(int start, int end) {
        if (start > end)
            return NULL;
        if (start == end)
            return new Segment(start, end, A[start]);
        int mid = start + ((end - start) >> 1);
        Segment *lt = buildTree(start, mid);
        Segment *rt = buildTree(mid + 1, end);
        Segment *root = new Segment(start, end, lt->sum + rt->sum);
        root->left = lt, root->right = rt;
        return root;
    }

    long long getSum(Segment *root, int start, int end) {
        if (root == NULL || start > root->ed || end < root->st)
            return 0;
        if (start <= root->st && end >= root->ed)
            return root->sum;
        int mid = root->st + ((root->ed - root->st) >> 1);
        if (end <= mid)
            return getSum(root->left, start, end);
        else if (start > mid)
            return getSum(root->right, start, end);
        else
            return getSum(root->left, start, mid) +
                    getSum(root->right, mid + 1, end);
    }

    long long update(Segment *root, int index, int value) {
        if (root == NULL || index < root->st || index > root->ed)
            return 0;
        if (index == root->st && index == root->ed) {
            long long r = value - root->sum;
            root->sum = value;
            return r;
        }
        int mid = root->st + ((root->ed - root->st) >> 1);
        long long up = 0;
        if (index <= mid)
            up = update(root->left, index, value);
        else
            up = update(root->right, index, value);
        root->sum += up;
        return up;
    }
};