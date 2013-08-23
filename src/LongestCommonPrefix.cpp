class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string str1;
        string str2;
        
        if (0 == strs.size())
        {
            // return empty string
            return str1;
        }
        
        if (1 == strs.size())
        {
            return strs[0];
        }
        
        for (string::size_type i = 0; (i < strs[0].size()) && (i < strs[1].size()) && (strs[0][i] == strs[1][i]); ++i)
        {
            str1.push_back(strs[0][i]);
        }
        
        for (vector<string>::size_type i = 2; i < strs.size(); ++i)
        {
            for (string::size_type j = 0; (j < str1.size()) && (j < strs[i].size()) && (str1[j] == strs[i][j]); ++j)
            {
                str2.push_back(str1[j]);
            }
            
            str1 = str2;
            str2.clear();
        }
        
        return str1;
    }
};
