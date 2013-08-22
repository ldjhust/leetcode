class Solution {
public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ((0 == num1.size()) || (0 == num2.size()))
        {
            return "";
        }
        
        if (("0" == num1) || ("0" == num2))
        {
            return "0";
        }
        
        if ("1" == num1)
        {
            return num2;
        }
        
        if ("1" == num2)
        {
            return num1;
        }
        
        string res;
        int carry = 0;
        
        for (int i = num1.size() - 1; i >= 0; --i)
        {
            carry = 0;
            int tmp;
            
            int pos = num1.size() - 1 - i;
            
            for (int j = num2.size() - 1; j >= 0; --j, ++pos)
            {
                tmp = (num1[i] - '0' + 0) * (num2[j] - '0' + 0) + carry;
                
                carry = tmp / 10;
                tmp %= 10;
                
                if (pos < res.size())
                {
                    tmp += res[pos] - '0' + 0;
                    
                    carry += tmp / 10;
                    tmp %= 10;
                    
                    res[pos] = (char)(tmp + '0');
                }
                else
                {
                    res.push_back((char)(tmp + '0'));
                }
            }
            
            if (carry != 0)
            {
                res.push_back((char)(carry + '0'));
            }
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};
