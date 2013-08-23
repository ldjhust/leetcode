class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (start.size() != end.size())
        {
            return 0;
        }
        
        if (start.empty() || end.empty())
        {
            return 1;
        }
        
        if (start == end)
        {
            return 0;
        }
        
        queue<string> queueToPush;
        queue<string> queueToPop;
        
        int distance = 1;
        
        queueToPop.push(start);
        
        while ((dict.size() > 0) && (!queueToPop.empty()))
        {
            while (!queueToPop.empty())
            {
                string str(queueToPop.front());
                
                queueToPop.pop();
                
                for (size_t i = 0; i < str.size(); ++i)
                {
                    for (char j = 'a'; j <= 'z'; ++j)
                    {
                        if (j == str[i])
                        {
                            continue;
                        }
                        
                        string tmp = str;
                        
                        str[i] = j;
                        
                        if (str == end)
                        {
                            return distance + 1;
                        }
                        
                        if (dict.count(str) > 0)
                        {
                            queueToPush.push(str);
                            dict.erase(str);
                        }
                        
                        str = tmp;
                    }
                }  
            }
            
            swap(queueToPop, queueToPush);
                
            ++distance;
        }
        
        return 0;
    }
};