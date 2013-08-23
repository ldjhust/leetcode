class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ((NULL == A) || (n <= 0))
        {
            return 0;
        }
        
        for (size_t i = 0; i < n;)
        {
            if (A[i] == elem)
            {
                A[i] = A[(n--) - 1];
            }
            else
            {
                ++i;
            }
        }
        
        return n;
    }
};
