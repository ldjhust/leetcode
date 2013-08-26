class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
        
        if (n < 0)
        {
            return res;
        }
        
        if (0 == n)
        {
            res.push_back(0);
            
            return res;
        }
        
        vector<int> v;
        int m = 1 << n;
        
        res.push_back(0);
        
        for (int i = 1; i < m; ++i)
        {
            v.push_back(i);
        }
        
        int num = 1;
        
        while (num < m)
        {
            if (num == (m - 1))
            {
                res.push_back(v[0]);
                break;
            }
            
            vector<int>::const_iterator it = res.end() - 1;
            
            for (vector<int>::iterator it1 = v.begin(); it1 != v.end(); ++it1)
            {
                int tmp = (*it) ^ (*it1);
                
                if (0 == (tmp & (tmp - 1)))
                {
                    res.push_back(*it1);
                    v.erase(it1);
                    
                    break;
                }
            }
            
            ++num;
        }
        
        return res;
    }
};
