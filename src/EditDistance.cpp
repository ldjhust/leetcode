class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (0 == word1.size())
        {
            return word2.size();
        }
        
        if (0 == word2.size())
        {
            return word1.size();
        }
        
        int ar[word1.size() + 1][word2.size() + 1];
        
        for (int i = 0; i <= word1.size(); ++i)
        {
            ar[i][0] = i;
        }
        
        for (int i = 0; i <= word2.size(); ++i)
        {
            ar[0][i] = i;
        }
        
        for (int i = 1; i <= word1.size(); ++i)
        {
            for (int j = 1; j <= word2.size(); ++j)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    ar[i][j] = ar[i-1][j-1];
                }
                else
                {
                    if (ar[i-1][j] < ar[i][j-1])
                    {
                        ar[i][j] = 1 + (ar[i-1][j] < ar[i-1][j-1] ? ar[i-1][j] : ar[i-1][j-1]);
                    }
                    else
                    {
                        ar[i][j] = 1 + (ar[i][j-1] < ar[i-1][j-1] ? ar[i][j-1] : ar[i-1][j-1]);
                    }
                }
            }
        }
        
        return ar[word1.size()][word2.size()];
    }
};
