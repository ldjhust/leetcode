class Solution {
public:
    void Re(vector<int> v, const int k, const vector<int> &S, int i, vector<vector<int>> &res)
    {
        if ((k < 0) || (0 == S.size()) || (i < 0))
        {
            return;
        }
        
        if (k == v.size())
        {
            res.push_back(v);
            
            return;
        }
        
        while (i < S.size())
        {
            v.push_back(S[i]);
            
            Re(v, k, S, i + 1, res);
            
            v.pop_back();
            
            ++i;
        }
    }
    
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> res;
        
        if (0 == S.size())
        {
            return res;
        }
        
        vector<int> v;
        
        sort(S.begin(), S.end());
        
        for (size_t i = 0; i <= S.size(); ++i)
        {
            Re(v, i, S, 0, res);
        }
        
        return res;
    }
};