class Solution {
public:
    /**
    * @param root: a TreeNode, the root of the binary tree
    * @return: nothing
    */
    void invertBinaryTree(TreeNode *root) {
        if (root == NULL)
            return;
        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        invertBinaryTree(root->left);
        invertBinaryTree(root->right);
    }
};