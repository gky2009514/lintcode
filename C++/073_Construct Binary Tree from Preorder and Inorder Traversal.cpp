class Solution {
    /**
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() == 0)
            return NULL;
        this->pre = preorder, this->in = inorder;
        return build(0, static_cast<int>(pre.size()) - 1,
                     0, static_cast<int>(in.size()) - 1);
    }

private:
    vector<int> pre, in;

    TreeNode *build(int pl, int pr, int il, int ir) {
        if (pl > pr)
            return NULL;
        if (pl == pr)
            return new TreeNode(pre[pl]);
        TreeNode *root = new TreeNode(pre[pl]);
        int i;
        for (i = il; i <= ir; i++) {
            if (in[i] == pre[pl])
                break;
        }
        root->left = build(pl + 1, pl + i - il, il, i - 1);
        root->right = build(pl + i - il + 1, pr, i + 1, ir);
        return root;
    }
};