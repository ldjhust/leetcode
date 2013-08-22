class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ((NULL == A) || (n <= 0))
        {
            return -1;
        }
        
        if (1 == n)
        {
            return 0;
        }
        
        int step = 1;
        unordered_set<int> s1;
        unordered_set<int> s2;
        
        s1.insert(0);
        
        while (!s1.empty())
        {
            while (!s1.empty())
            {
                unordered_set<int>::iterator it = s1.begin();
                int index = *it;
                
                s1.erase(it);
                
                int i = 1;
                
                while (i <= A[index])
                {
                    if ((index + i) >= (n - 1))
                    {
                        return step;
                    }
                    
                    s2.insert(index + i);
                    
                    ++i;
                }
            }
            
            ++step;
            swap(s1, s2);
        }
        
        return step;
    }
};
