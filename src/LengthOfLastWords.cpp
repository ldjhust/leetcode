class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (NULL == s)
        {
            return 0;
        }
        
        size_t uCount = 0;
        int i = strlen(s) - 1;
        
        while ((i >= 0) && (' ' == s[i]))
        {
            --i;
        }
        
        for (; i >= 0; --i)
        {
            if ((('A' <= s[i]) && ('Z' >= s[i])) || (('a' <= s[i]) && ('z' >= s[i])))
            {
                ++uCount;
            }
            else
            {
                break;
            }
        }
        
        return uCount;
    }
};
