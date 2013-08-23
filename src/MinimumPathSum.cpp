class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        size_t m = grid.size();
        size_t n = grid[m-1].size();
        vector<int> res(n, 0);
        
        res[0] = grid[0][0];
        
        for (size_t i = 1; i < n; ++i)
        {
            res[i] = res[i-1] + grid[0][i];
        }
        
        size_t i = 1;
        
        while (i < m)
        {
            size_t j = 0;
            
            res[j] += grid[i][j];
            
            ++j;
            
            while (j < n)
            {
                res[j] = (res[j-1] < res[j]) ? (res[j-1] + grid[i][j]) : (res[j] + grid[i][j]);
                
                ++j;
            }
            
            ++i;
        }
        
        return res[n-1];
    }
};