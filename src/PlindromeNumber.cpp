class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        // if a number is palindrome, than it's reverse must be equal to itself
        if (x < 0)
        {
            return false;
        }
        
        int xCopy = x;
        int reverse = 0;
        
        while (xCopy != 0)
        {
            reverse *= 10;
            reverse += xCopy % 10;
            xCopy /= 10;
        }
        
        if (x == reverse)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
