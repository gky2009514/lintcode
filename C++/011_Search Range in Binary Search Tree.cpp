class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        vector<int> res;
        this->k1 = k1, this->k2 = k2;
        inVisit(root, res);
        return res;
    }

private:
    int k1, k2;
    void inVisit(TreeNode *root, vector<int> &r) {
        if (root == NULL)
            return;
        if (root->val >= k1)
            inVisit(root->left, r);
        if (root->val >= k1 && root->val <= k2)
            r.push_back(root->val);
        if (root->val <= k2)
            inVisit(root->right, r);
    }
};