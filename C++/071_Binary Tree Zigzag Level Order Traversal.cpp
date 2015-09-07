class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: A list of lists of integer include
     *          the zigzag level order traversal of its nodes' values
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > visit;
        levelOrder(root, visit, 1);
        for (int i = 0; i < visit.size(); i++) {
            if (i & 1)
                reverse(visit[i].begin(), visit[i].end());
        }
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