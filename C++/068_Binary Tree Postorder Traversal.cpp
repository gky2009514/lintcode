class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        post.clear();
        postVisit(root);
        return post;
    }

private:
    vector<int> post;

    void postVisit(TreeNode *root) {
        if (root == NULL)
            return;
        postVisit(root->left);
        postVisit(root->right);
        post.push_back(root->val);
    }
};