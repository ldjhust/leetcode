class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> vec;
        
        if (numRows <= 0)
        {
            return vec;
        }
        
        for (int i = 0; i < numRows; ++i)
        {
            vector<int> tmp;
            
            for (int j = 0; j <= i; ++j)
            {
                if ((0 == j) || (j == i))
                {
                    tmp.push_back(1);
                    continue;
                }
                
                tmp.push_back(vec[i-1][j-1] + vec[i-1][j]);
            }
            
            vec.push_back(tmp);
        }
        
        return vec;
    }
};
