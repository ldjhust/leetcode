class Solution {
public:
    int Factor(int n)
    {
        if (n <= 1)
        {
            return 1;
        }
        
        int res = 1;
        
        while (n > 1)
        {
            res *= n;
            --n;
        }
        
        return res;
    }

    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int tmp;
        
        tmp = Factor(n);
        k %= tmp;
        
        if (0 == k)
        {
            k = tmp;
        }
        
        string res;
        
        for (int i = 1; i <= n; ++i)
        {
            res.push_back((char)(i + '0'));
        }
        
        if (k > (tmp >> 1))
        {
            k = tmp - k + 1;
            
            prev_permutation(res.begin(), res.end());
            
            for (int i = 2; i <= k; ++i)
            {
                prev_permutation(res.begin(), res.end());
            }
        }
        else
        {
            for (int i = 2; i <= k; ++i)
            {
                next_permutation(res.begin(), res.end());
            }
        }
        
        return res;
    }
};
