class Solution {
public:
    bool Re(vector<vector<char>> board, const int i, const int j, const string word, const int k)
    {
        /*
        if ((0 == board.size() || (0 == word.size()))
        {
            return false;
        }
        */
        
        if ((i < 0) || (j < 0))
        {
            return false;
        }
        
        if (k == word.size())
        {
            return true;
        }
        
        if (board[i][j] == word[k])
        {
            board[i][j] = '#';  // 用过的字母不能再用第二遍
            
            // down
            if (i < (board.size() - 1))
    		{
				if ((board[i + 1][j] != '#') && Re(board, i + 1, j, word, k + 1))
				{
					return true;
				}
			}
			
            // up
			if (i > 0)
			{
				if ((board[i - 1][j] != '#') &&Re(board, i - 1, j, word, k + 1))
				{
					return true;
				}
			}
			
            // right
			if (j < (board[0].size() - 1))
			{
				if ((board[i][j + 1] != '#') &&Re(board, i, j + 1, word, k + 1))
				{
					return true;
				}
			}
			
            
            // left
			if (j > 0)
			{
				if ((board[i][j - 1] != '#') &&Re(board, i, j - 1, word, k + 1))
				{
					return true;
				}
			}
			
			if (k == word.size() - 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }

    bool exist(vector<vector<char> > &board, string word)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ((0 == board.size()) || (0 == word.size()))
        {
            return false;
        }
        
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] == word[0])
                {
                
                    if (Re(board, i, j, word, 0))
                    {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};