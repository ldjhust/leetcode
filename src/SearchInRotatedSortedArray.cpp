class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ((NULL == A) || (n <= 0))
        {
            return -1;
        }
        
        int i = 0;
        int j = n - 1;
        
        int mid;
        
        while (i <= j)
        {
            mid = i + ((j - i) >> 1);
            
            if (A[mid] == target)
            {
                return mid;
            }
            else if (A[mid] > target)
            {
                if (A[j] >= target)
                {
                    if (A[j] > A[mid])
                    {
                        j = mid - 1;
                    }
                    else
                    {
                        i = mid + 1;
                    }
                }
                else
                {
                    j = mid - 1;
                }
            }
            else
            {
                if (A[j] < target)
                {
                    if (A[mid] < A[j])
                    {
                        j = mid - 1;
                    }
                    else
                    {
                        i = mid + 1;
                    }
                }
                else
                {
                    i = mid + 1;
                }
            }
        }
        
        return -1;
    }
};
