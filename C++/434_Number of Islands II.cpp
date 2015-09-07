class Solution {
public:
    /**
    * @param n an integer
    * @param m an integer
    * @param operators an array of point
    * @return an integer array
    */
    vector<int> numIslands2(int n, int m, vector<Point>& operators) {
        if (n == 0 || m == 0)
            return vector<int>();
        this->n = n, this->m = m;
        island = vector<vector<bool> >(n, vector<bool>(m, false));
        father.clear();
        for (int i = 0; i < n * m; i++)
            father.push_back(i);
        int num = 0;
        vector<int> nums;
        for (int i = 0; i < operators.size(); i++) {
            int x = operators[i].x, y = operators[i].y;
            if (island[x][y]) {
                nums.push_back(num);
                continue;
            }
            addIsland(x, y, num);
            nums.push_back(num);
        }
        return nums;
    }

private:
    int n, m;
    int direct[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
    vector<vector<bool> > island;
    vector<int> father;

    int findFather(int x) {
        if (father[x] != x)
            father[x] = findFather(father[x]);
        return father[x];
    }

    void addIsland(int x, int y, int &num) {
        island[x][y] = true;
        num++;
        for (int i = 0; i < 4; i++) {
            int nx = x + direct[i][0];
            int ny = y + direct[i][1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || !island[nx][ny])
                continue;
            int nfa = findFather(nx * m + ny);
            int fa = findFather(x * m + y);
            if (nfa != fa) {
                father[nfa] = fa;
                num--;
            }
        }
    }
};