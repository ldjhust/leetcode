class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        // use binary search
        if ((NULL == A) || (n <= 0))
        {
            return -1;
        }
        
        int i = 0;
        int j = n - 1;
        
        while (i < j)
        {
            int mid = i + ((j - i) >> 1);
            
            if (A[mid] == target)
            {
                return mid;
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
        
        if (A[i] >= target)
        {
            return i;
        }
        else
        {
            return i + 1;
        }
    }
};
