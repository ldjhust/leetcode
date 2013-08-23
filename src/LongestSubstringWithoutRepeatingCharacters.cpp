class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (0 == s.size())
        {
            return 0;
        }
        
        size_t max = 0;
        size_t hash[256];
        
        for (string::size_type i = 0; i < s.size(); ++i)
        {
            memset(hash, 0, 256 * sizeof(size_t));
            
            ++hash[s[i] + 0];
            
            for (string::size_type j = i + 1; j < s.size(); ++j)
            {
                if (0 == hash[s[j] + 0])
                {
                    ++hash[s[j] + 0];
                    ++hash[s[i] + 0];
                }
                else
                {
                    break;
                }
            }
            
            if (max < hash[s[i] + 0])
            {
                max = hash[s[i] + 0];
            }
        }
        
        return max;
    }
};
