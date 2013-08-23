class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ((NULL == A) || (n <= 0))
        {
            return false;
        }
        
        if (1 == n)
        {
            return true;
        }
        
        if (0 == A[0])
        {
            return false;
        }
        
        int i = 0;
        int j = i + 1;
        int max = A[0];
        
        while (j < n)
        {
            if (A[j] != 0)
            {
                ++i;
                ++j;
                
                if (A[i] > max)
                {
                    max = A[i];
                }
                
                continue;
            }
            
            int count = 0;
            
            while ((0 == A[j]) && (j < n)) 
            {
                ++count;
                ++j;
            }
            
            if (A[i] <= count)
            {
                if ((j >= n) && (A[i] == count))
                {
                    return true;
                }
                
                while (A[i] <= count)
                {
                    if ((0 == A[i]) || (A[i] == max))
                    {
                        return false;
                    }
                    
                    --i;
                    ++count;
                }
            }
            
            i = j;
            ++j;
        }
        
        return true;
    }
};