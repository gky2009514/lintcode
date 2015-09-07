class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0)
            return 0;
        vector<vector<int> > paths(obstacleGrid.size(),
                                   vector<int>(obstacleGrid[0].size(), 0));
        paths[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
        for (int i = 1; i < obstacleGrid.size(); i++) {
            if (obstacleGrid[i][0] == 1)
                paths[i][0] = 0;
            else
                paths[i][0] = paths[i - 1][0];
        }
        for (int i = 1; i < obstacleGrid[0].size(); i++) {
            if (obstacleGrid[0][i] == 1)
                paths[0][i] = 0;
            else
                paths[0][i] = paths[0][i - 1];
        }
        for (int i = 1; i < obstacleGrid.size(); i++) {
            for (int j = 1; j < obstacleGrid[0].size(); j++) {
                if (obstacleGrid[i][j] == 1)
                    paths[i][j] = 0;
                else
                    paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
            }
        }
        return paths[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};