class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ((m <= 0) || (n <= 0))
        {
            return 0;
        }
        
        size_t a = m + n - 2;
        size_t b = m - 1;
        
        // C(m, n) == C(m, m - n)
        if (b > (a / 2))
        {
            b = a - b;
        }
        
        if ((0 == b) || (a == b))
        {
            return 1;
        }
        
        if (1 == b)
        {
            return a;
        }
        
        // C(m, n) = C(m - 1, n) + C(m - 1, n - 1), 参照0 1背包空间优化的思想可以优化为只用一维数组存储如下
        size_t *C = new size_t[b+1];
        
        for (size_t i = 0; i <= b; ++i)
        {
            C[i] = 1;
        }
        
        for (size_t i = 2; i <= a; ++i)
        {
        	for (size_t j = i - 1; j >= 1; --j)
        	{
                if (j > b)
                {
                	// 大于b的j没有意义
                    continue;
                }
                
        		C[j] += C[j-1];
        		
        		if ((i == a) && (j == b))
        		{
                    size_t tmp = C[j];
                    
                    delete [] C;
                    
        			return tmp;
        		}
        	}
        }
    }
};
