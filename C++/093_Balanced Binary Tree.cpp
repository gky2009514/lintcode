class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        if (root == NULL)
            return true;
        int lh = 0, rh = 0;
        if (!check(root->left, lh) || !check(root->right, rh))
            return false;
        if (abs(lh - rh) > 1)
            return false;
        return true;
    }

private:
    bool check(TreeNode *root, int &height) {
        height = 0;
        if (root == NULL)
            return true;
        int lh = 0, rh = 0;
        if (!check(root->left, lh) || !check(root->right, rh))
            return false;
        if (abs(lh - rh) > 1)
            return false;
        height = max(lh, rh) + 1;
        return true;
    }
};