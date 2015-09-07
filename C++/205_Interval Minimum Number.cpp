class Solution {
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<int> intervalMinNumber(vector<int> &A, vector<Interval> &queries) {
        vector<int> res;
        int n = static_cast<int>(A.size());
        if (n == 0)
            return res;
        Segment *root = buildTree(A, 0, n - 1);
        for (int i = 0; i < queries.size(); i++)
            res.push_back(queryMin(root, queries[i].start, queries[i].end));
        return res;
    }

private:
    struct Segment {
        int st, ed, mi;
        Segment *left, *right;
        Segment(int s, int e, int m) {
            st = s, ed = e, mi = m;
            left = right = NULL;
        }
    };

    Segment *buildTree(const vector<int> &A, int l, int r) {
        if (l > r)
            return NULL;
        if (l == r) {
            Segment *root = new Segment(l, r, A[l]);
            return root;
        }
        int mid = l + ((r - l) >> 1);
        Segment *lt = buildTree(A, l, mid);
        Segment *rt = buildTree(A, mid + 1, r);
        Segment *root = new Segment(l, r, min(lt->mi, rt->mi));
        root->left = lt, root->right = rt;
        return root;
    }

    int queryMin(Segment *root, int start, int end) {
        if (root == NULL || start > root->ed || end < root->st)
            return 0;
        if (start <= root->st && end >= root->ed)
            return root->mi;
        int mid = root->st + ((root->ed - root->st) >> 1);
        if (end <= mid)
            return queryMin(root->left, start, end);
        else if (start > mid)
            return queryMin(root->right, start, end);
        else
            return min(queryMin(root->left, start, mid), queryMin(root->right, mid + 1, end));
    }
};