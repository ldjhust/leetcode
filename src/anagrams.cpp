class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> res;
        
        if (0 == strs.size())
        {
            return res;
        }
        
        map<string, int> m;
        map<string, int>::iterator it;
        string tmp;
        
        for (int i = 0; i < strs.size(); ++i)
        {
            tmp = strs[i];
            
            sort (tmp.begin(), tmp.end());
            
            it = m.find(tmp);
            
            if (m.end() == it)
            {
                m.insert(pair<string, int>(tmp, i));
                continue;
            }
            
            if (it->second != -1)
            {
                res.push_back(strs[it->second]);
                it->second = -1;
                res.push_back(strs[i]);
            }
            else
            {
                res.push_back(strs[i]);
            }
        }
        
        return res;
    }
};