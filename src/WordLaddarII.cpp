class Solution {
public:
    bool Check(string wordone, string wordtwo)
    {
        if ((0 == wordone.size()) || (0 == wordtwo.size()))
        {
            return false;
        }
        
        if (wordone.size() != wordtwo.size())
        {
            return false;
        }
        
        if (wordone[0] == wordtwo[0])
        {
            wordone.erase(wordone.begin());
            wordtwo.erase(wordtwo.begin());
            
            Check(wordone, wordtwo);
        }
        else
        {
            wordone[0] = wordtwo[0];
            
            if (wordone == wordtwo)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string>> vec;
        
        if (0 == dict.size())
        {
            return vec;
        }
        
        if (Check(start, end))
        {
            vector<string> str;
            
            str.push_back(start);
            str.push_back(end);
            
            vec.push_back(str);
            
            return vec;
        }
        
        vector<vector<string>> q;
        vector<string> qTmp;
        
        qTmp.push_back(start);
        q.push_back(qTmp);
        
        size_t size = 1;
        
        while (size < q.size())
        {
        	qTmp = q[size-1];
        	
        	vector<string> qInsert;
        	
        	for (size_t i = 0; i < qTmp.size(); ++i)
        	{
            	for (unordered_set<string>::const_iterator iter = dict.begin(); iter != dict.end();)
            	{
                	if (start == *iter)
               		{
                	    ++iter;
                	    dict.erase(start);
                	    
                	    continue;
                	}
                
                	if (end == *iter)
                	{
                	    ++iter;
                	    dict.erase(end);
                    
                	    continue;
                	}
                
                	if (Check(qTmp[i], *iter))
                	{	
                	    qInsert.push_back(*iter);                
                    
                	    string tmp = *iter++;
                	    dict.erase(tmp);
                	}
                	else
                	{
                	    ++iter;
                	}
            	}
            }       
        }
        
        return vec;
    }
};
