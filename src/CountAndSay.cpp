class Solution {
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n <= 0)
        {
            return "";
        }
        
        string str1("1");
        string strTmp;
        size_t Count =0;
        
        for (size_t i = 2; i <= n; ++i)
        {
            for (string::const_iterator iter = str1.begin(); iter != str1.end();)
            {
                char ch = *iter;
                
                Count = 0;
                
                while ((iter != str1.end()) && (ch == *iter))
                {
                    ++Count;
                    ++iter;
                }
                
                strTmp.push_back(static_cast<char>(Count + '0'));
                strTmp.push_back(ch);
            }
            
            str1 = strTmp;
            strTmp.clear();
        }
        
        return str1; 
    }
};
