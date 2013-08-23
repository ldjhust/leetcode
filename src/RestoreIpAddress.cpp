class Solution {
public:
    void restoreIpAddresses(const string s, const int start, string res, vector<string> &vec, const int i, int dotNum)
    {
        if ((i < 1) || (i > 4))
        {
            return;
        }
        
        if (((s.size() - start) < i) || ((s.size() - start) > 3 * i))
        {
            return;
        }
        
        if (1 == i)
        {
            if (dotNum < 3)
            {
                return;
            }
            
            if (('0' == s[start]) && ((s.size() - start) > 1))
            {
                return;
            }
            
            if (3 == (s.size() - start))
            {
                string str;

                str.push_back(s[start]);
		        str.push_back(s[start + 1]);
		        str.push_back(s[start + 2]);
                
                if (str > "255")
                {
		            return;
                }
                
                res += str;
            
                vec.push_back(res);
            
                return;
            }
            else if ((s.size() - start) < 3)
            {
                int index = start;
                
                while (index != s.size())
                {
                    res.push_back(s[index++]);
                }
                
                vec.push_back(res);
                
                return;
            }
            else
            {
                return;
            }
        }
        
        string::size_type index = start;
        
        string sFlag;
        bool bFlag = false;
        
        if ('0' == s[index])
        {
            bFlag = true;
        }
        
        sFlag.push_back(s[index]);
        
        res.push_back(s[index]);
        res.push_back('.');
        
        ++dotNum;
        
        restoreIpAddresses(s, start + 1, res, vec, i - 1, dotNum);
        
        res.pop_back();
        --dotNum;
        
        if (bFlag)
        {
            return;
        }
        
        if (++index != s.size())
        {
            sFlag.push_back(s[index]);
            
            res.push_back(s[index]);
            res.push_back('.');
            ++dotNum;
        
            restoreIpAddresses(s, start + 2, res, vec, i - 1, dotNum);
        
            res.pop_back();
            --dotNum;
            
            if (++index != s.size())
            {
                sFlag.push_back(s[index]);
                
                if (sFlag > "255")
                {
                    return;
                }
                
                res.push_back(s[index]);
                res.push_back('.');
                ++dotNum;
        
                restoreIpAddresses(s, start + 3, res, vec, i - 1, dotNum);
            }
        }
        
        return;
    }

    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> vec;
        
        if ((s.size() < 4) || (s.size() > 12))
        {
            return vec;
        }
        
        string res;
        
        restoreIpAddresses(s, 0, res, vec, 4, 0);
        
        return vec;
    }
};