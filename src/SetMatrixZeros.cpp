class Solution {
public:
    void setZeros(vector<vector<int>> &m, const size_t i, const size_t j)
    {
        if ((i > m.size()) || (j > m[0].size()))
        {
            return;
        }
        
        if (m[i][j] != 0)
        {
            if ((i == m.size() - 1) && (j == m[0].size() - 1))
            {
                return;
            }
            
            if (j == m[0].size() - 1)
            {
                setZeros(m, i + 1, 0);
            }
            else
            {
                setZeros(m, i, j + 1);
            }
        }
        else
        {
            if ((i == m.size() - 1) && (j == m[0].size() - 1))
            {
                for (int k = 0; k < m.size(); ++k)
                {
                    m[k][j] = 0;
                }
                
                for (int k = 0; k < m[0].size(); ++k)
                {
                    m[i][k] = 0;
                }
                
                return;
            }
            
            if (j == m[0].size() - 1)
            {
                setZeros(m, i + 1, 0);
            }
            else
            {
                setZeros(m, i, j + 1);
            }
            
            for (int k = 0; k < m.size(); ++k)
            {
                m[k][j] = 0;
            }
            
            for (int k = 0; k < m[0].size(); ++k)
            {
                m[i][k] = 0;
            }
        }
    }

    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ((0 == matrix.size()) || (0 == matrix[0].size()))
        {
            return;
        }
        
        setZeros(matrix, 0, 0);
    }
};
