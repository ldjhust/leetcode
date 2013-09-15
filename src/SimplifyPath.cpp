class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (0 == path.size())
        {
            return "";
        }
        
        string res;
        vector<string> v;
        
        for (string::const_iterator it = path.begin(); it != path.end(); ++it)
        {
            if (*it != '/')
            {
                res.push_back(*it);
                continue;
            }
            
            res.push_back(*it);
            
            if ("/" == res)
            {
                if (0 == v.size())
                {
                    v.push_back(res);
                }
                
                res.clear();
                continue;
            }
            
            if ("./" == res)
            {
                res.clear();
                continue;
            }
            else if ("../" == res)
            {
                if (v.size() > 1)
                {
                    v.pop_back();
                }
            }
            else
            {
                v.push_back(res);
            }
            
            res.clear();
        }
        
        if ("." == res)
        {
            res.clear();
        }
        else if (".." == res)
        {
            if (v.size() > 1)
            {
                v.pop_back();
            }
            
            res.clear();
        }
        else
        {
            v.push_back(res);   
            res = "";
        }
        
        for (vector<string>::const_iterator it = v.begin(); it != v.end(); ++it)
        {
            res += *it;
        }
        
        if (('/' == res[res.size() - 1]) && (res.size() > 1))
        {
            res.pop_back();
        }
        
        return res;
    }
};
