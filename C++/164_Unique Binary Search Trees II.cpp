class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: A list of root
     */
    vector<TreeNode *> generateTrees(int n) {
        return genTrees(1, n);
    }

private:
    vector<TreeNode*> genTrees(int st, int ed) {
        vector<TreeNode*> res;
        if (st > ed) {
            res.push_back(NULL);
            return res;
        }
        for (int i = st; i <= ed; i++) {
            vector<TreeNode*> l = genTrees(st, i - 1);
            vector<TreeNode*> r = genTrees(i + 1, ed);
            for (int j = 0; j < l.size(); j++) {
                for (int k = 0; k < r.size(); k++) {
                    TreeNode *root = new TreeNode(i);
                    root->left = l[j], root->right = r[k];
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};