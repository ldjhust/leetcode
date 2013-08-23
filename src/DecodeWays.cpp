class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		
		// 斐波那契的变种
		
        if (0 == s.size())
        {
            return 0;
        }
        
        if ('0' == s[0])
        {
            return 0;
        }
        
        if (1 == s.size())
        {
            if ('0' == s[0])
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }

        int f1 = 1;
        int f2;
        
        if (((s[0] - '0' + 0) * 10 + (s[1] - '0' + 0) > 26) || ('0' == s[1]))
        {
            if (('0' == s[1]) && (s[0] > '2'))
            {
                return 0;
            }
            
            f2 = 1;
        }
        else
        {
            f2 = 2;
        }
        
        for (int i = 2; i < s.size(); ++i)
        {
            if ('0' == s[i])
            {
                if (('0' == s[i-1]) || (s[i-1] > '2'))
                {
                    return 0;
                }
                
                swap(f1, f2);
            }
            else if ((s[i-1] > '2') || ('0' == s[i-1]))
            {
                f1 = f2;
            }
            else if (('2' == s[i-1]) && (s[i] > '6'))
            {
                f1 == f2;
            }
            else
            {
                f1 += f2;
            
                swap(f1, f2);
            }
        }
        
        return f2;
    }
};