class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ((NULL == A) || (n < 0))
        {
            return -1;
        }
        
        if (n < 2)
        {
            return n;
        }
        
        for (size_t i = 0; i < (n - 1); ++i)
        {
            size_t j = i + 1;
            size_t Count = 0;
            
            while ((j < n) && (A[j] == A[i]))
            {
                ++Count;
                ++j;
            }
            
            if (Count > 0)
            {
                size_t k = i + 1;
                
                while ((k < n) && (j < n))
                {
                    A[k++] = A[j++];
                }
                
                n -= Count;
            }
        }
        
        return n;
    }
};
