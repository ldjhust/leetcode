class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> vec;
        set<vector<int>> s;
        
        if (num.size() < 3)
        {
            return vec;
        }
        
        sort(num.begin(), num.end());
        
        if (num[0] > 0)
        {
            return vec;
        }
        
        for (int i = num.size() - 1; i >= 0; --i)
        {
            int j = i - 1;
            int k = 0;
            
            while (k < j)
            {
                if (num[k] + num[j] == -1 * num[i])
                {
                    vector<int> v;
                
                    v.push_back(num[k]);
                    v.push_back(num[j]);
                    v.push_back(num[i]);
                
                    s.insert(v);
                    
                    --j;
                }
                else if (num[k] + num[j] > -1 * num[i])
                {
                    --j;
                }
                else
                {
                    ++k;
                }
            }
        }
        
        for (set<vector<int>>::const_iterator it = s.begin(); it != s.end(); ++it)
        {
            vec.push_back(*it);
        }
        
        return vec;
    }
};
