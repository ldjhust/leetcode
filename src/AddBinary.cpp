class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (0 == a.size())
        {
            return b;
        }
        
        if (0 == b.size())
        {
            return a;
        }
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        string res;
        size_t carry = 0;
        size_t i = 0;
        
        for (; (i < a.size()) && (i < b.size()); ++i)
        {
            size_t tmp = (a[i] - '0' + 0) + (b[i] - '0' + 0) + carry;
            
            carry = tmp / 2;
            res.push_back(static_cast<char>(tmp % 2 + '0'));
        }
        
        while (i < a.size())
        {
            size_t tmp = (a[i++] - '0' + 0) + carry;
            
            carry = tmp / 2;
            res.push_back(static_cast<char>(tmp % 2 + '0'));
        }
        
        while (i < b.size())
        {
            size_t tmp = (b[i++] - '0' + 0) + carry;
            
            carry = tmp / 2;
            res.push_back(static_cast<char>(tmp % 2 + '0'));
        }
        
        if (carry != 0)
        {
            res.push_back(static_cast<char>(carry + '0'));
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};
