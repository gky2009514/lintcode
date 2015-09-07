class Solution {
public:
    /**
     *@param root, index, value: The root of segment tree and
     *@ change the node's value with [index, index] to the new given value
     *@return: void
     */
    void modify(SegmentTreeNode *root, int index, int value) {
        if (root == NULL || index < root->start || index > root->end)
            return;
        int st = root->start, ed = root->end;
        if (st == ed) {
            root->max = value;
            return;
        }
        if (index <= (st + ed) / 2)
            modify(root->left, index, value);
        else
            modify(root->right, index, value);
        root->max = max(root->left->max, root->right->max);
    }
};