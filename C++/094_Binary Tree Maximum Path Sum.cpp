class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxPathSum(TreeNode *root) {
        ma = INT_MIN;
        dfs(root);
        return ma;
    }

private:
    int ma;
    int dfs(TreeNode *root) {
        if (root == NULL)
            return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        ma = max(ma, root->val + l + r);
        int t = root->val + max(l, r);
        ma = max(ma, t);
        return max(t, 0);
    }
};