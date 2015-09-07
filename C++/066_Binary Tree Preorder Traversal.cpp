class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> order;
        preorder(root, order);
        return order;
    }

private:
    void preorder(TreeNode *root, vector<int> &order) {
        if (root == NULL)
            return;
        order.push_back(root->val);
        preorder(root->left, order);
        preorder(root->right, order);
    }
};