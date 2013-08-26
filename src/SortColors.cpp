class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ((NULL == A) || (n <= 0))
        {
            return;
        }
        
        if (1 == n)
        {
            return;
        }
        
        int i = 0;
        int j = n - 1;
        int val = 2;
        
        while (val >= 0)
        {
            i = 0;
            
            while (i < j)
            {
                while ((i < j) && (val == A[j]))
                {
                    --j;
                }
                
                while ((i < j) && (A[i] != val))
                {
                    ++i;
                }
                
                if (i < j)
                {
                    swap(A[i], A[j]);
                }
            }
            
            --val;
        }
    }
};
