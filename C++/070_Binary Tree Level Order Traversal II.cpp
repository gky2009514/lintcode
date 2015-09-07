class Solution {
    /**
     * @param root : The root of binary tree.
     * @return : buttom-up level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int> > visit;
        levelOrder(root, visit, 1);
        reverse(visit.begin(), visit.end());
        return visit;
    }

private:
    void levelOrder(TreeNode *root, vector<vector<int> > &visit, int level) {
        if (root == NULL)
            return;
        if (level > visit.size())
            visit.push_back(vector<int>());
        visit[level - 1].push_back(root->val);
        levelOrder(root->left, visit, level + 1);
        levelOrder(root->right, visit, level + 1);
    }
};