class Solution {
public:
    double ComputePow(const double x, const size_t n)
    {
        if (0 == n)
        {
            return 1;
        }
        
        if (1 == n)
        {
            return x;
        }
        
        double res = x;
        int i = 1;
        size_t N = n >> 1;
        
        while (i <= N)
        {
            res *= res;
            i <<= 1;
        }
        
        
        if ((i >> 1) == N)
        {
            if (0 == n % 2)
            {
                return res;
            }
            else
            {
                return res * x;
            }
        }
        
        res *= ComputePow(x, n - i);
        
        return res;
    }

    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (0 == n)
        {
            return 1.0;
        }
        
        if (abs(x) < 1e-5)
        {
            if (n > 0)
            {
                return 0.0;
            }
            else
            {
                return 1.0;
            }
        }
        
        
        if (n < 0)
        {
            x = 1.0 / x;
            n *= -1;
        }
        
        return ComputePow(x, n);
    }
};