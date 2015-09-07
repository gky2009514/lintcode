class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        if (root == NULL)
            return true;
        if (root->left) {
            int lmi = 0, lma = 0;
            if (!isValid(root->left, lmi, lma) || lma >= root->val)
                return false;
        }
        if (root->right) {
            int rmi = 0, rma = 0;
            if (!isValid(root->right, rmi, rma) || rmi <= root->val)
                return false;
        }
        return true;
    }

private:
    bool isValid(TreeNode *root, int &mi, int &ma) {
        mi = ma = root->val;
        if (root->left) {
            int lmi = 0, lma = 0;
            if (!isValid(root->left, lmi, lma) || lma >= root->val)
                return false;
            mi = lmi;
        }
        if (root->right) {
            int rmi = 0, rma = 0;
            if (!isValid(root->right, rmi, rma) || rmi <= root->val)
                return false;
            ma = rma;
        }
        return true;
    }
};