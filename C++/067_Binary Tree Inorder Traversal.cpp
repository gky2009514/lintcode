class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }

private:
    void inorder(TreeNode *root, vector<int> &r) {
        if (root == NULL)
            return;
        inorder(root->left, r);
        r.push_back(root->val);
        inorder(root->right, r);
    }
};