class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        if (A == NULL || B == NULL)
            return A == NULL ? B : A;
        while (!sa.empty())
            sa.pop();
        while (!sb.empty())
            sb.pop();
        if (findNode(root, A, sa) && findNode(root, B, sb)) {
            TreeNode *pre = NULL;
            while (!sa.empty() && !sb.empty()) {
                if (sa.top() != sb.top())
                    break;
                pre = sa.top();
                sa.pop(), sb.pop();
            }
            return pre;
        }
        return NULL;
    }

private:
    stack<TreeNode*> sa, sb;

    bool findNode(TreeNode *root, TreeNode *f, stack<TreeNode*> &s) {
        if (f == root) {
            s.push(root);
            return true;
        }
        if (root == NULL)
            return false;
        if (findNode(root->left, f, s) || findNode(root->right, f, s)) {
            s.push(root);
            return true;
        }
        return false;
    }
};