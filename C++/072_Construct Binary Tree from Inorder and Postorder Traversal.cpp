class Solution {
    /**
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.size() == 0)
            return NULL;
        this->in = inorder, this->post = postorder;
        return build(0, static_cast<int>(inorder.size()) - 1,
                     0, static_cast<int>(postorder.size()) - 1);
    }

private:
    vector<int> in, post;

    TreeNode *build(int il, int ir, int pl, int pr) {
        if (il > ir)
            return NULL;
        TreeNode *root = new TreeNode(post[pr]);
        int i;
        for (i = il; i <= ir; i++) {
            if (in[i] == post[pr])
                break;
        }
        root->left = build(il, i - 1, pl, pl + i - 1 - il);
        root->right = build(i + 1, ir, pl + i - il, pr - 1);
        return root;
    }
};