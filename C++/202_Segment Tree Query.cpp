class Solution {
public:
    /**
     *@param root, start, end: The root of segment tree and
     *                         an segment / interval
     *@return: The maximum number in the interval [start, end]
     */
    int query(SegmentTreeNode *root, int start, int end) {
        if (root == NULL || end < root->start || start > root->end)
            return 0;
        int st = root->start, ed = root->end;
        if (st == start && ed == end)
            return root->max;
        if (start > (st + ed) / 2)
            return query(root->right, start, end);
        else if (end <= (st + ed) / 2)
            return query(root->left, start, end);
        else
            return max(query(root->left, start, (st + ed) / 2),
                       query(root->right, (st + ed) / 2 + 1, end));
    }
};