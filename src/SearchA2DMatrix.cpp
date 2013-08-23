class Solution {
public:
    bool BinarySearch(const vector<int> &mat, const int target)
    {
        if (0 == mat.size())
        {
            return 0;
        }
        
        int i = 0;
        int j = mat.size() - 1;
        
        while (i <= j)
        {
            int mid = i + ((j - i) >> 1);
            
            if (mat[mid] == target)
            {
                return true;
            }
            else if (mat[mid] > target)
            {
                j = mid - 1;
            }
            else
            {
                i = mid + 1;
            }
        }
        
        return false;
    }

    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (0 == matrix.size())
        {
            return false;
        }
        
        if ((target < matrix[0][0]) || (target > matrix[matrix.size() - 1][matrix[0].size() - 1]))
        {
            return false;
        }
        
        for (size_t i = 0; i < matrix.size(); ++i)
        {
            if (BinarySearch(matrix[i], target))
            {
                return true;
            }
        }
        
        return false;
    }
};