class Solution {
public:
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ((NULL == s) || (0 == strlen(s)))
        {
            return false;
        }
        
        size_t i = 0;
        size_t j = strlen(s) - 1;
        
        while ((' ' == s[i]) && (i <= j))
        {
            ++i;
        }
        
        while ((' ' == s[j]) && (j >= i))
        {
            --j;
        }
        
        if (('+' == s[i]) || ('-' == s[i]))
        {
            ++i;
        }
        
        if ((i > j) || ('e' == s[i]) || ('E' == s[i]))
        {
            return false;
        }
        
        if (('.' == s[i]) && ('e' == s[i+1]) || ('E' == s[i+1]))
        {
            return false;
        }
        
        size_t dotCount = 0;
        size_t eCount = 0;
        
        for (size_t k = i; k <= j; ++k)
        {
            if ((dotCount > 1) || (eCount > 1))
            {
                break;
            }
            
            if ('.' == s[k])
            {
                if ((k == i) && (k == j) || (eCount > 0))
                {
                    return false;
                }
                
                ++dotCount;
                continue;
            }
            
            if (('e' == s[k]) || ('E' == s[k]))
            {
                if (k == j)
                {
                    return false;
                }
                
                if (('+' == s[k+1]) || ('-' == s[k+1]))
                {
                    if ((k + 1) == j)
                    {
                        return false;
                    }
                    
                    ++k;
                }
                
                ++eCount;
                continue;
            }
            
            if ((s[k] < '0') || (s[k] > '9'))
            {
                return false;
            }
        } // end for
        
        if ((dotCount > 1) || (eCount > 1))
        {
            return false;
        }
        else
        {
            return true;
            
        }
    }
};
