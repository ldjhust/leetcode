class Solution {
public:
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if (num <= 0)
        {
            return "";
        }
        
        string table[3][10];
        
        for (size_t i = 0; i < 3; ++i)
        {
            for (size_t j = 0; j < 10; ++j)
            {
                table[i][j] = " ";
                
                if (1 == j)
                {
                    switch (i)
                    {
                        case 0:
                        {
                            table[i][j] = "I";
                            break;
                        }
                        case 1:
                        {
                            table[i][j] = "X";
                            break;
                        }
                        case 2:
                        {
                            table[i][j] = "C";
                            break;
                        }
                    }
                }
                
                if (4 == j)
                {
                    switch (i)
                    {
                        case 0:
                        {
                            table[i][j] = "IV";
                            break;
                        }
                        case 1:
                        {
                            table[i][j] = "XL";
                            break;
                        }
                        case 2:
                        {
                            table[i][j] = "CD";
                            break;
                        }
                    }
                }
                
                if (5 == j)
                {
                    switch (i)
                    {
                        case 0:
                        {
                            table[i][j] = "V";
                            break;
                        }
                        case 1:
                        {
                            table[i][j] = "L";
                            break;
                        }
                        case 2:
                        {
                            table[i][j] = "D";
                            break;
                        }
                    }
                }
                
                if (9 == j)
                {
                    switch (i)
                    {
                        case 0:
                        {
                            table[i][j] = "IX";
                            break;
                        }
                        case 1:
                        {
                            table[i][j] = "XC";
                            break;
                        }
                        case 2:
                        {
                            table[i][j] = "CM";
                            break;
                        }
                    }
                }
            }
        }
        
        int thou = num / 1000;
        
        if (thou > 0)
        
        {
            num %= 1000;
        }
        
        int hand = num / 100;
        
        if (hand > 0)
        {
            num %= 100;
        }
        
        int ten = num / 10;
        int di = num % 10;
        
        string res("");
        
        while (thou-- > 0)
        {
            res.push_back('M');
        }
        
        if (hand > 0)
        {
        
            if (" " == table[2][hand])
            {
                size_t n = 0;
            
                while (" "== table[2][hand--])
                {
                    ++n;
                }
            
                res += table[2][hand+1];
            
                while (n-- > 0)
                {
                    res.push_back('C');
                }
            }
            else
            {
                res += table[2][hand];
            }
        }
        
        if (ten > 0)
        {
            if (" " == table[1][ten])
            {
                size_t n = 0;
            
                while (" "== table[1][ten--])
                {
                    ++n;
                }
            
                res += table[1][ten+1];
            
                while (n-- > 0)
                {
                    res.push_back('X');
                }
            }
            else
            {
                res += table[1][ten];
            }
        }
        
        if (di > 0)
        {
            if (" " == table[0][di])
            {
                size_t n = 0;
            
                while (" "== table[0][di--])
                {
                    ++n;
                }
            
                res += table[0][di+1];
            
                while (n-- > 0)
                {
                    res.push_back('I');
                }
            }
            else
            {
                res += table[0][di];
            }
        }
        
        return res;
    }
};
