class Solution {
public:
    /**
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        if (T2 == NULL)
            return true;
        if (T1 == NULL)
            return false;
        if (completeMatch(T1, T2))
            return true;
        return isSubtree(T1->left, T2) || isSubtree(T1->right, T2);
    }

private:
    bool completeMatch(TreeNode *T1, TreeNode *T2) {
        if (T1 == NULL && T2 == NULL)
            return true;
        if (T1 == NULL || T2 == NULL || T1->val != T2->val)
            return false;
        return completeMatch(T1->left, T2->left) &&
                completeMatch(T1->right, T2->right);
    }
};