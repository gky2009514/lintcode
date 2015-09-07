class Solution {
public:
    /**
     *@param start, end: Denote an segment / interval
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(int start, int end) {
        if (start > end)
            return NULL;
        SegmentTreeNode *root = new SegmentTreeNode(start, end);
        if (start < end) {
            root->left = build(start, (start + end) >> 1);
            root->right = build((start + end) / 2 + 1, end);
        }
        return root;
    }
};