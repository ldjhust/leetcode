class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (0 == obstacleGrid.size())
        {
            return 0;
        }
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> res(n + 1, 0);
        int i = n - 1;
        
        --m;
        
        while ((i >= 0) && (obstacleGrid[m][i] == 0))
        {
            res[i--] = 1;
        }
        
        while (--m >= 0)
        {
            for (i = n - 1; i >= 0; --i)
            {
                res[i] = (1 == obstacleGrid[m][i]) ? 0 : (res[i] + res[i + 1]);
            }
        }
        
        return res[0];
    }
};