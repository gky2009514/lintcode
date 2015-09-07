class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int minDepth(TreeNode *root) {
        if (root == NULL)
            return 0;
        if (root->left == NULL)
            return 1 + minDepth(root->right);
        if (root->right == NULL)
            return 1 + minDepth(root->left);
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        return 1 + min(l, r);
    }
};