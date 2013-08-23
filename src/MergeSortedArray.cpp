class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ((NULL == A) || (m < 0) || (NULL == B) || (n < 0))
        {
            return;
        }
        
        int *C = new int[m + n];
        
        size_t i = 0;
        size_t j = 0;
        size_t k = 0;
        
        while ((i < m) && (j < n))
        {
            if (A[i] <= B[j])
            {
                C[k++] = A[i++];
            }
            else
            {
                C[k++] = B[j++];
            }
        }
        
        while (i < m)
        {
            C[k++] = A[i++];
        }
        
        while (j < n)
        {
            C[k++] = B[j++];
        }
        
        for (i = 0; i < (m + n); ++i)
        {
            A[i] = C[i];
        }
        
        delete [] C;
    }
};
