class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ((NULL == A) || (n <= 0))
        {
            return 0;
        }
        
        size_t count = 0;
        
        for (size_t i = 0; i < n;)
        {
            size_t k = i;
            int tmp = A[i];
            
            count = 0;
            while ((tmp == A[i]) && (i < n))
            {
                ++count;
                ++i;
            }
            
            if (count <= 2)
            {
                continue;
            }
            
            k += 2;
            
            // remenber k
            size_t indexTmp = k;
            
            for (size_t j = i; j < n; ++j)
            {
                A[k++] = A[j];
            }
            
            // i's new start
            i = indexTmp;
            
            n -=count - 2;
        }
        
        return n;
    }
};
