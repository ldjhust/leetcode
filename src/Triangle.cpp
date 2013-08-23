class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<int> res(n, 0);
        
        res[0] = triangle[0][0];
        int i = 1;
        int min = res[0];
        
        while (i < m)
        {
            int j = triangle[i].size() - 1;
            
            res[j] = res[j-1] + triangle[i][j];
            min = res[j];
            
            --j;
            
            for (; j > 0; --j)
            {
                res[j] = (res[j] < res[j-1]) ? (res[j] + triangle[i][j]) : (res[j-1] + triangle[i][j]);
                min = (min < res[j]) ? min : res[j];
            }
            
            res[j] += triangle[i][j];
            min = (min < res[j]) ? min : res[j];
            
            ++i;
        }
        
        
        return min;
    }
};