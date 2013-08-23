class Solution {
public:
    
    template<typename T>
    void Swap(T &a, T &b)
    {
        if (a == b)
        {
            return;
        }
        
        a ^= b;
        b ^= a;
        a ^= b;
    }
    
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n <= 0)
        {
            return 0;
        }
        
        if (1 == n)
        {
            return 1;
        }
        
        if (2 == n)
        {
            return 2;
        }
        
        size_t f1 = 1;
        size_t f2 = 2;
        
        for (size_t i = 3; i <= n; ++i)
        {
            f1 += f2;
            
            Swap(f1, f2);
        }
        
        return f2;
    }
};
