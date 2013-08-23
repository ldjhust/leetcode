class Solution {
public:
    void Re(vector<int> v, const int k, int i, const int n, vector<vector<int>> &res)
    {
        if ((k <= 0) || (n <= 0) || (k > n))
        {
            return;
        }
        
        if (k == v.size())
        {
            res.push_back(v);
            
            return;
        }
        
        while (i <= n)
        {
            v.push_back(i);
            
            Re(v, k, i + 1, n, res);
            
            v.pop_back();
            
            ++i;
        }
    }
    
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> res;
        
        if ((n <= 0) || (k <= 0) || (n < k))
        {
            return res;
        }
        
        vector<int> v;
        
        Re(v, k, 1, n, res);
        
        return res;
    }
};