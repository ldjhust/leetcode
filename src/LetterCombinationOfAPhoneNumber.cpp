class Solution {
public:
    void Re(const string &num, size_t i, const vector<string> &v, vector<string> &vec, string &str)
    {
        if (i == num.size())
        {
            if ("" != str)
            {
                vec.push_back(str);            
            }
            
            return;
        }
        
        for (string::const_iterator it = v[num[i] - '0' + 0].begin(); it != v[num[i] - '0' + 0].end(); ++it)
        {
            str.push_back(*it);
            
            Re(num, i + 1, v, vec, str);
            
            str.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> vec;
        string str("");
        
        if (0 == digits.size())
        {        
            vec.push_back(str);
            
            return vec;
        }
        
        vector<string> v;
        
        v.push_back(str);
        v.push_back(str);
        
        str = "abc";
        
        for (size_t i = 2; i < 8; ++i)
        {
            v.push_back(str);
            
            str[0] += 3;
            str[1] += 3;
            str[2] += 3;
        }
        
        v[7].push_back('s');
        v.push_back("tuv");
        v.push_back("wxyz");
        
        str = "";
        
        Re(digits, 0, v, vec, str);
        
        return vec;
    }
};
