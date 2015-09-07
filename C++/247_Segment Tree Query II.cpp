class Solution {
public:
    /**
     *@param root, start, end: The root of segment tree and
     *                         an segment / interval
     *@return: The count number in the interval [start, end]
     */
    int query(SegmentTreeNode *root, int start, int end) {
        if (root == NULL || start > root->end || end < root->start)
            return 0;
        int st = root->start, ed = root->end;
        if (st == start && ed == end)
            return root->count;
        if (end <= (st + ed) / 2)
            return query(root->left, max(st, start), end);
        else if (start > (st + ed) / 2)
            return query(root->right, start, min(ed, end));
        else
            return query(root->left, max(st, start), (st + ed) / 2) +
                    query(root->right, (st + ed) / 2 + 1, min(ed, end));
    }
};