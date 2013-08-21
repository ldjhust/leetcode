class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (0 == dividend)
        {
            return 0;
        }
        
        if (dividend == divisor)
        {
            return 1;
        }
        
        int sign = 1;
        
        if (dividend < 0)
        {
            sign = ~(sign - 1);
            dividend = ~(dividend - 1);
        }
        
        
        
        if (divisor < 0)
        {
            sign = ~(sign - 1);
            divisor = ~(divisor - 1);
        }
        
        unsigned int a = (unsigned int)dividend;
        unsigned int b = (unsigned int)divisor;
        
        
        
        int res = 0;
        
        for (int i = 31; i >= 0; --i)
        {
            if ((a >> i) >= b)
            {
                res += 1 << i;
                a -= b << i;
            }
        }
        
        
        if (sign < 0)
        {
            res = ~(res - 1);
        }
        
        return res;
    }
};
