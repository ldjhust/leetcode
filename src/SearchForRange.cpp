class Solution {
public:
    int BSearch(const int *A, const int s, const int e, const int target)
    {
        if ((NULL == A) || (s < 0) || (s > e))
        {
            return -1;
        }
        
        int i = s;
        int j = e;
        
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
                j = mid - 1;
            }
            else
            {
                i = mid + 1;
            }
        }
        
        return -1;
    }

    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> vec(2, -1);
        
        if ((NULL == A) || (n <= 0))
        {
            return vec;
        }
        
        int index = BSearch(A, 0, n - 1, target);
        
        int mid = index;
        
        while (mid != -1)
        {
            vec[1] = mid;
            mid = BSearch(A, mid + 1, n - 1, target);
        }
        
        mid = index;
        
        while (mid != -1)
        {
            vec[0] = mid;
            mid = BSearch(A, 0, mid - 1, target);
        }
        
        return vec;
    }
};
