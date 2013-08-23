class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<char> st;
        
        if (0 == s.size())
        {
            return true;
        }
        
        for (string::const_iterator iter = s.begin(); iter != s.end(); ++iter)
        {
            if (('(' == *iter) || ('[' == *iter) || ('{' == *iter))
            {
                st.push(*iter);
            }
            else
            {
                if (st.empty())
                {
                    return false;
                }
                
                if ((('(' == st.top()) && (')' == *iter)) || (('[' == st.top()) && (']' == *iter))
                    || (('{' == st.top()) && ('}' == *iter)))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        
        if (st.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
