class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: an integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int> > &matrix, int k) {
        int n = static_cast<int>(matrix.size());
        int m = static_cast<int>(matrix[0].size());
        if (n <= 0 || m <= 0 || k <= 0 || k > n * m)
            return 0;
        vector<vector<bool> > visit(n, vector<bool>(m, false));
        priority_queue<node> pq;
        pq.push(node(matrix[0][0], 0, 0));
        visit[0][0] = true;
        node frt(0, 0, 0);
        while (k--) {
            frt = pq.top();
            pq.pop();
            if (frt.y + 1 < m && !visit[frt.x][frt.y + 1]) {
                pq.push(node(matrix[frt.x][frt.y + 1], frt.x, frt.y + 1));
                visit[frt.x][frt.y + 1] = true;
            }
            if (frt.x + 1 < n && !visit[frt.x + 1][frt.y]) {
                pq.push(node(matrix[frt.x + 1][frt.y], frt.x + 1, frt.y));
                visit[frt.x + 1][frt.y] = true;
            }
        }
        return frt.num;
    }

private:
    struct node {
        int num, x, y;
        node(int n, int x, int y): num(n), x(x), y(y) {}
        bool operator < (const node &a) const {
            return num > a.num;
        }
    };
};