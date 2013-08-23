class Solution {
public:
    bool isPalindrome(const string &s)
    {
        if (s.size() <= 1)
        {
            return true;
        }
        
        int i = 0;
        int j = s.size() - 1;
        
        while ((i < j) && (s[i] == s[j]))
        {
            ++i;
            --j;
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

    void palindromePartition(const string &s, const size_t start, vector<string> tmp, vector<vector<string>> &res)
    {
        if (0 == s.size())
        {
            return;
        }
        
        if (start == s.size())
        {
            res.push_back(tmp);
            
            return;
        }
        
        string str;
        
        for (size_t i = start; i < s.size(); ++i)
        {
            str.push_back(s[i]);
            
            if (isPalindrome(str))
            {
                tmp.push_back(str);
                
                palindromePartition(s, i + 1, tmp, res);
                
                tmp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string>> res;
        
        if (0 == s.size())
        {
            return res;
        }
        
        vector<string> tmp;
        
        palindromePartition(s, 0, tmp, res);
        
        return res;
    }
};