class Solution {
public:
    /**
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    TreeNode *sortedArrayToBST(vector<int> &A) {
        int n = static_cast<int>(A.size());
        if (n == 0)
            return NULL;
        return toBST(A, 0, n - 1);
    }

private:
    TreeNode *toBST(const vector<int> &A, int l, int r) {
        if (l > r)
            return NULL;
        int mid = l + ((r - l) >> 1);
        TreeNode *root = new TreeNode(A[mid]);
        root->left = toBST(A, l, mid - 1);
        root->right = toBST(A, mid + 1, r);
        return root;
    }
};