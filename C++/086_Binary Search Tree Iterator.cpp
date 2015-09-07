class Solution {
public:
    // @param root: The root of binary tree.
    Solution(TreeNode *root) {
        now = root;
        while (!father.empty())
            father.pop();
        while (now) {
            father.push(now);
            now = now->left;
        }
    }

    // @return: True if there has next node, or false
    bool hasNext() {
        if (now && now->right)
            return true;
        return !father.empty();
    }

    // @return: return next node
    TreeNode* next() {
        if (now && now->right) {
            now = now->right;
            while (now) {
                father.push(now);
                now = now->left;
            }
        }
        now = father.top();
        father.pop();
        return now;
    }

private:
    TreeNode *now;
    stack<TreeNode*> father;
};