class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> vec;
        
        if (0 == num.size())
        {
            return vec;
        }
        
        vec.push_back(num);
        
        next_permutation(num.begin(), num.end());
        
        while (num != vec[0])
        {
            vec.push_back(num);
            
            next_permutation(num.begin(), num.end());
        }
        
        return vec;
    }
};