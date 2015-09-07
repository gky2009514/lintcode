class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode *root) {
        if (root == NULL)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};