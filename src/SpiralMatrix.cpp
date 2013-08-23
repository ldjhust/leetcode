class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> vec;
        
        if (n <= 0)
        {
            return vec;
        }
        
        vector<int> v(n);
        
        for (int i = 0; i < n; ++i)
        {
            vec.push_back(v);
        }
        
        int ele = 1;
        int size = n * n;
        int i = 0;
        int j = 0;
        int n_size = n - 1;
        
        while (ele <= size)
        {
            if (n_size <= 0)
            {
                if (0 != n % 2)
                {
                    vec[i][j] = ele;
                }
                
                break;
            }
            
            int tmp = n_size;
            
            while (tmp > 0)
            {
                vec[i][j] = ele++;
                ++j;
                --tmp;
            }
            
            tmp = n_size;
            
            while (tmp > 0)
            {
                vec[i][j] = ele++;
                ++i;
                --tmp;
            }
            
            tmp = n_size;
            
            while (tmp > 0)
            {
                vec[i][j] = ele++;
                --j;
                --tmp;
            }
            
            tmp = n_size;
            
            while (tmp > 0)
            {
                vec[i][j] = ele++;
                --i;
                --tmp;
            }
            
            n_size -= 2;
            
            // 新的内圈的循环起点
            ++i;
            ++j;
        }
        
        return vec;
    }
};