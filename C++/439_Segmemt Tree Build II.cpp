class Solution {
public:
    /**
     *@param A: a list of integer
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(vector<int>& A) {
        int n = static_cast<int>(A.size());
        return buildRange(A, 0, n - 1);
    }

private:
    SegmentTreeNode *buildRange(const vector<int> &A, int l, int r) {
        if (l > r)
            return NULL;
        if (l == r)
            return new SegmentTreeNode(l, r, A[l]);
        int mid = l + ((r - l) >> 1);
        SegmentTreeNode *lt = buildRange(A, l, mid);
        SegmentTreeNode *rt = buildRange(A, mid + 1, r);
        SegmentTreeNode *root = new SegmentTreeNode(l, r, max(lt->max, rt->max));
        root->left = lt, root->right = rt;
        return root;
    }
};