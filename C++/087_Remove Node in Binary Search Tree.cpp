class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode* removeNode(TreeNode* root, int value) {
        if (root == NULL)
            return NULL;
        TreeNode *find = root, *parent = NULL;
        while (find != NULL && find->val != value) {
            parent = find;
            find = find->val < value ? find->right : find->left;
        }
        if (find == NULL)
            return root;
        if (parent == NULL)
            return deleteNode(root, NULL);
        deleteNode(find, parent);
        return root;
    }

private:
    TreeNode *deleteNode(TreeNode *root, TreeNode *parent) {
        int value = root->val;
        TreeNode *res = root;
        if (root->left == NULL || root->right == NULL) {
            res = root->left == NULL ? root->right : root->left;
            if (parent) {
                if (value < parent->val)
                    parent->left = res;
                else
                    parent->right = res;
            }
        } else {
            TreeNode *del = root->right, *pre = root;
            while (del->left) {
                pre = del;
                del = del->left;
            }
            root->val = del->val;
            deleteNode(del, pre);
        }
        return res;
    }
};