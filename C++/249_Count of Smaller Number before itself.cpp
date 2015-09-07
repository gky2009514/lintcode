class Solution {
public:
    /**
     * @param A: An integer array
     * @return: Count the number of element before this element 'ai' is
     *          smaller than it and return count number array
     */
    vector<int> countOfSmallerNumberII(vector<int> &A) {
        vector<int> res;
        int n = static_cast<int>(A.size());
        if (n == 0)
            return res;
        Segment *root = new Segment(A[0], A[0], 1);
        res.push_back(0);
        for (int i = 1; i < n; i++)
            res.push_back(update(root, A[i]));
        return res;
    }

private:
    struct Segment {
        int st, ed, count;
        Segment *left, *right;
        Segment(int s, int e, int c) {
            st = s, ed = e, count = c;
            left = right = NULL;
        }
    };

    Segment *buildLeft(int st, int ed) {
        Segment *root = new Segment(st, ed, 1);
        if (st == ed)
            return root;
        root->left = new Segment(st, st, 1);
        root->right = new Segment(st + 1, ed, 0);
        return root;
    }

    Segment *buildRight(int st, int ed) {
        Segment *root = new Segment(st, ed, 1);
        if (st == ed)
            return root;
        root->left = new Segment(st, ed - 1, 0);
        root->right = new Segment(ed, ed, 1);
        return root;
    }

    int update(Segment *&root, int num) {
        if (num > root->ed) {
            int r = root->count;
            Segment *nd = new Segment(root->st, num, r + 1);
            nd->left = root;
            nd->right = buildRight(root->ed + 1, num);
            root = nd;
            return r;
        }
        if (num < root->st) {
            Segment *nd = new Segment(num, root->ed, root->count + 1);
            nd->left = buildLeft(num, root->st - 1);
            nd->right = root;
            root = nd;
            return 0;
        }
        root->count++;
        if (root->st == root->ed)
            return 0;
        if (root->left) {
            if (num > root->left->ed)
                return update(root->right, num) + root->left->count;
            return update(root->left, num);
        } else {
            root->left = buildRight(root->st, num);
            root->right = new Segment(num + 1, root->ed, 0);
            return 0;
        }
    }
};