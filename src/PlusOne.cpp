class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (0 == digits.size())
        {
            return digits;
        }
        
        size_t Carry = 0;
        int tmp = digits[digits.size() - 1] + 1;
        
        Carry = tmp / 10;
        digits[digits.size() - 1] = tmp % 10;
        
        for (int i = digits.size() - 2; i >= 0; --i)
        {
            if (0 == Carry)
            {
                break;
            }
            
            tmp = digits[i] + Carry;
            Carry = tmp / 10;
            digits[i] = tmp % 10;
        }
        
        if (Carry != 0)
        {
            digits.insert(digits.begin(), Carry);
        }
        
        return digits;
    }
};
