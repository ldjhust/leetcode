class Solution {
public:
    void FindSum(const vector<int> &C, const size_t s, vector<int> tmp, set<vector<int>> &res, const int target)
    {
        if (s >= C.size())
        {
            return;
        }
        
        for (size_t i = s; i < C.size(); ++i)
        {
            if (C[i] == target)
            {
                tmp.push_back(C[i]);
                res.insert(tmp);
                tmp.pop_back();
                
                continue;
            }
            
            if (C[i] < target)
            {
                tmp.push_back(C[i]);
                FindSum(C, i + 1, tmp, res, target - C[i]);
                tmp.pop_back();
            }
            else
            {
                return;
            }
        }
    }

    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> res;
        
        if (0 == num.size())
        {
            return res;
        }
        
        sort(num.begin(), num.end());
        
        vector<int> tmp;
        set<vector<int>> se;
        
        FindSum(num, 0, tmp, se, target);
        
        for (set<vector<int>>::const_iterator it = se.begin(); it != se.end(); ++it)
        {
            res.push_back(*it);
        }
        
        return res;
    }
};
