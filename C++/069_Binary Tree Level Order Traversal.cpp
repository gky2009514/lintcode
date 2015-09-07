class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int> > level;
        levelVisit(root, level, 1);
        return level;
    }

private:
    void levelVisit(TreeNode *root, vector<vector<int> > &level, int depth) {
        if (root == NULL)
            return;
        if (depth > level.size())
            level.push_back(vector<int>());
        level[depth - 1].push_back(root->val);
        levelVisit(root->left, level, depth + 1);
        levelVisit(root->right, level, depth + 1);
    }
};