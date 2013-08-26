class Solution {
public:
    void subset(const vector<int> &S, set<vector<int>> &tmp, vector<int> &vec, const size_t start, const size_t num)
    {
        if (vec.size() == num)
        {
            tmp.insert(vec);
            
            return;
        }
        
        for (size_t i = start; i < S.size(); ++i)
        {
            if ((S.size() - i) < (num - vec.size()))
            {
                return;
            }
            
            vec.push_back(S[i]);
            
            subset(S, tmp, vec, i + 1, num);
            
            vec.pop_back();
        }
    }

    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> res;
        vector<int> vec;
        
        res.push_back(vec);
        
        if (0 == S.size())
        {
            return res;
        }
        
        sort(S.begin(), S.end());
        
        set<vector<int>> tmp;
        size_t num = 1;
        
        while (num <= S.size())
        {
            subset(S, tmp, vec, 0, num);
            
            ++num;
        }
        
        for (set<vector<int>>::const_iterator it = tmp.begin(); it != tmp.end(); ++it)
        {
            res.push_back(*it);
        }
        
        return res;
    }
};
