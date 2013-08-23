class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (0 == s.size())
        {
            return true;
        }
        
        int i = 0;
        int j = s.size() - 1;
        
        while (i < j)
        {
            if (((s[i] < 'A') || (s[i] > 'Z')) && ((s[i] < 'a') || (s[i] > 'z')) && ((s[i] < '0') || (s[i] > '9')))
            {
                ++i;
                continue;
            }
            
            if (((s[j] < 'A') || (s[j] > 'Z')) && ((s[j] < 'a') || (s[j] > 'z')) && ((s[j] < '0') || (s[j] > '9')))
            {
                --j;
                continue;
            }
            
            if ((s[i] == s[j]) || (abs(s[i] - s[j] + 0) == ('a' - 'A' + 0)))
            {
                ++i;
                --j;
            }
            else
            {
                break;
            }
        }
        
        if (i < j)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};
