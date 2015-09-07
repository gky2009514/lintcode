class Solution {
public:
    /**
     * @param A: Given an integer array with no duplicates.
     * @return: The root of max tree.
     */
    TreeNode* maxTree(vector<int> A) {
        int n = static_cast<int>(A.size());
        if (n == 0)
            return NULL;
        stack<int> stk;
        vector<int> leftFr(n, 0);
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && A[stk.top()] < A[i])
                stk.pop();
            if (stk.empty())
                leftFr[i] = -1;
            else
                leftFr[i] = stk.top();
            stk.push(i);
        }
        vector<TreeNode*> nodes(n, NULL);
        TreeNode *root = NULL;
        for (int i = 0; i < n; i++) {
            TreeNode *now = new TreeNode(A[i]);
            nodes[i] = now;
            if (leftFr[i] == -1) {
                now->left = root;
                root = now;
            } else {
                TreeNode *pre = nodes[leftFr[i]];
                TreeNode *r = pre->right;
                pre->right = now;
                now->left = r;
            }
        }
        return root;
    }
};