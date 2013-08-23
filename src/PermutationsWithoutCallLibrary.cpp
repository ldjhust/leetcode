class Solution {
public:
    void Swap(int &a, int &b)
    {
        if (a != b)
        {
            a ^= b;
            b ^= a;
            a ^= b;
        }
    }

    void Permutation(vector<int> &num, int i, vector<int> &numTmp, set<vector<int>> &s)
    {
        if (0 == num.size())
        {
            return;
        }
        
        if (i == num.size())
        {
            s.insert(num);
            
            return;
        }
        
        for (vector<int>::iterator it = numTmp.begin(); it != numTmp.end(); ++it)
        {
            Swap(*it, numTmp[i]);
            
            Permutation(num, i + 1, numTmp, s);
            
            Swap(*it, numTmp[i]);
        }
    }

    void Permutation(vector<int> &num, set<vector<int>> &s)
    {
        if (0 == num.size())
        {
            return;
        }
        
        Permutation(num, 0, num, s);
    }

    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> vec;
        
        if (0 == num.size())
        {
            return vec;
        }
        
        set<vector<int>> s;
        
        Permutation(num, s);
        
        for (set<vector<int>>::const_iterator it = s.begin(); it != s.end(); ++it)
        {
            vec.push_back(*it);
        }
        
        return vec;
    }
};