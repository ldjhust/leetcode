class Solution {
public:
    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ((NULL == A) || (n <= 0))
        {
            return false;
        }
        
        int i;
        
        for (i = 1; i < n; ++i)
        {
            if (A[i] < A[i-1])
            {
                break;
            }
        }
        
        if (i < n)
        {
            reverse(A, A + i);
            reverse(A + i, A + n);
            reverse(A, A + n);
        }
        
        i = 0;
        int j = n - 1;
        
        while (i <= j)
        {
            int mid = i + ((j - i) >> 1);
            
            if (A[mid] == target)
            {
                return true;
            }
            else if (A[mid] > target)
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
};
