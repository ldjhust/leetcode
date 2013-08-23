class Solution {
public:
    bool valid(const string &str)
    {
        if (str.size() <= 1)
        {
            return false;
        }
        
        stack<char> s;
        
        string::const_iterator it = str.begin();
        
        while (it != str.end())
        {
            if ('(' == *it)
            {
                s.push(*it++);
            }
            else
            {
                if ((0 == s.size()) || ('(' != s.top()))
                {
                    break;
                }
                
                s.pop();
                ++it;
            }
        }
        
        if ((s.empty()) && (it == str.end()))
        {
            return true;
        }
        
        return false;
    }

    void DFS(string str, vector<string> &res, int n)
    {
        if (str.size() == n)
        { 
            if (valid(str))
            {
                res.push_back(str);
            }            
            
            return;
        }
        
        str.push_back('(');
        
        DFS(str, res, n);
        
        str.pop_back();
        
        str.push_back(')');
        
        DFS(str, res, n);   
        
        str.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> res;
        string str;
        
        if (n <= 0)
        {
            return res;
        }
        
        str.push_back('(');
        
        DFS(str, res, 2 * n);
        
        return res;
    }
};
