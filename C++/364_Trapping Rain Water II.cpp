class Solution {
public:
    /**
     * @param heights: a matrix of integers
     * @return: an integer
     */
    int trapRainWater(vector<vector<int> > &heights) {
        n = static_cast<int>(heights.size());
        if (n < 3)
            return 0;
        m = static_cast<int>(heights[0].size());
        if (m < 3)
            return 0;
        priority_queue<point> pq;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                pq.push(point(i, j, heights[i][j]));
        }
        total = 0;
        while (!pq.empty()) {
            point t = pq.top();
            pq.pop();
            if (heights[t.x][t.y] != t.h)
                continue;
            bfs(t, heights);
            if (heights[t.x][t.y] != -1)
                pq.push(point(t.x, t.y, heights[t.x][t.y]));
        }
        return total;
    }

private:
    struct point {
        int x, y, h;
        point(int x, int y, int h): x(x), y(y), h(h) {}
        bool operator < (const point &a) const {
            return h > a.h;
        }
    };
    static const int N = 4;
    int n, m, total;
    int direct[N][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void bfs(const point &p, vector<vector<int> > &heights) {
        queue<point> qb;
        vector<point> vb;
        qb.push(p);
        heights[p.x][p.y] = -2;
        int ma = INT_MAX;
        bool flow = true;
        while (!qb.empty()) {
            point ft = qb.front();
            qb.pop();
            vb.push_back(ft);
            for (int i = 0; i < N; i++) {
                int nx = ft.x + direct[i][0];
                int ny = ft.y + direct[i][1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    flow = false;
                    continue;
                }
                if (heights[nx][ny] == -2)
                    continue;
                if (heights[nx][ny] < p.h) {
                    flow = false;
                } else if (heights[nx][ny] == p.h) {
                    qb.push(point(nx, ny, p.h));
                    heights[nx][ny] = -2;
                } else {
                    ma = min(ma, heights[nx][ny]);
                }
            }
        }
        for (int i = 0; i < vb.size(); i++) {
            if (flow) {
                total += ma - vb[i].h;
                heights[vb[i].x][vb[i].y] = ma;
            } else {
                heights[vb[i].x][vb[i].y] = -1;
            }
        }
    }
};