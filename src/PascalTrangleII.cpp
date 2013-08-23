class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> vec;
        
        for (int i = 0; i <= rowIndex; ++i)
        {
            for (int j = i; j >= 0; --j)
            {
                if (i == j)
                {
                    vec.push_back(1);
                    continue;
                }
                
                if (0 == j)
                {
                    continue;
                }
                
                vec[j] += vec[j-1];
            }
        }
        
        return vec;
    }
};
