class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> res;
        
        if (0 == num.size())
        {
            return res;
        }
        
        vector<int> tmp = num;
        set<vector<int>> s;
        
        s.insert(num);
        
        next_permutation(num.begin(), num.end());
        
        while (num != tmp)
        {
            s.insert(num);
            
            next_permutation(num.begin(), num.end());
        }
        
        for (set<vector<int>>::const_iterator it = s.begin(); it != s.end(); ++it)
        {
            res.push_back(*it);
        }
        
        return res;
    }
};
