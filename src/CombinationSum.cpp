class Solution {
public:
    void Recursion(const vector<int> &candidates, const int i, const int target, vector<int> v, set<vector<int>> &s)
    {
        if (i == candidates.size())
        {
            return;
        }
        
        if (target == candidates[i])
        {
            v.push_back(candidates[i]);
            
            s.insert(v);
            
            v.pop_back();
            
            Recursion(candidates, i + 1, target, v, s);
        }
        
        if (target < candidates[i])
        {
            return;
        }
        
        if (target > candidates[i])
        {
            v.push_back(candidates[i]);
            
            Recursion(candidates, i + 1, target - candidates[i], v, s);
            
            Recursion(candidates, i, target - candidates[i], v, s);
            
            v.pop_back();
            
            Recursion(candidates, i + 1, target, v, s);
        }
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> vec;
        
        if (0 == candidates.size())
        {
            return vec;
        }
        
        set<vector<int>> s;
        vector<int> v;
        
        sort(candidates.begin(), candidates.end());
        
        Recursion(candidates, 0, target, v, s);
        
        for (set<vector<int>>::const_iterator it = s.begin(); it != s.end(); ++it)
        {
            vec.push_back(*it);
        }
        
        return vec;
    }
};