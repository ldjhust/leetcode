class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ((NULL == A) || (n <= 0))
        {
            return 0;
        }
        
        int i = 0;
        
        while (((i + 1) < n) && (A[i+1] >= A[i]))
        {
            ++i;
        }
        
        if ((i + 1) >= n)
        {
            return 0;
        }
        
        int j = n - 1;
        
        while (((j - 1) > i) && (A[j-1]) >= A[j])
        {
            --j;
        }
        
        if ((j - 1) <= i)
        {
            return 0;
        }
        
        int res = 0;
        
        while (i < j)
        {
            int min = A[i] < A[j] ? A[i] : A[j];
            
            for (int k = i + 1; k < j; ++k)
            {
                if (A[k] < min)
                {
                    res += min - A[k];
                    
                    A[k] = min; // 去掉下一轮重复将计算的部分
                }
            }
            
            if (A[i] == A[j])
            {
                ++i;
                
                while ((i < j) && (A[i] <= min))
                {
                    ++i;
                }
                
                if (i >= j)
                {
                    break;
                }
                
                --j;
                
                while ((j > i) && (A[j] <= min))
                {
                    --j;
                }
                
                if (j <= i)
                {
                    break;
                }
                
                continue;
            }
            
            if (min == A[i])
            {
                ++i;
                
                while ((i < j) && (A[i] <= min))
                {
                    ++i;
                }
                
                if (i >= j)
                {
                    break;
                }
            }
            else
            {
                --j;
                
                while ((j > i) && (A[j] <= min))
                {
                    --j;
                }
                
                if (j <= i)
                {
                    break;
                }
            }
        }
        
        return res;
    }
};
