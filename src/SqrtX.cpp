class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x < 0)
        {
            return -1;
        }
        
        int i = 1;
        int j = (x >> 1) + 1;
        
        while (i <= j)
        {
            int mid = i + ((j - i) >> 1);
            
            if (mid > 46340)
            {
                j = mid - 1;
                
                continue;
            }
            
            int tmp = mid * mid;
            
            if (tmp == x)
            {
                return mid;
            }
            else if (tmp > x)
            {
                j = mid - 1;
            }
            else
            {
                i = mid + 1;
            }
        }
        
        return j;
    }
};
